import torch
import torch.nn as nn
import torch.optim as optim
import torchvision.transforms as transforms
import torchvision
from torch.utils.data import DataLoader
import os
import torch
import pandas as pd
from torch.utils.data import Dataset
from skimage import io

class CatsAndDogsDataset(Dataset):
    def __init__(self, csv_file, root_dir, transform=None) :
        self.anotations = pd.read_csv(csv_file)
        self.root_dir = root_dir
        self.transform = transform

    def __len__(self):
        return len(self.anotations)

    def __getitem__(self, index):
        img_path = os.path.join(self.root_dir, self.anotations.iloc[index, 0])
        image = io.imread(img_path)
        y_label = torch.tensor(int(self.anotations.iloc[index, 1]))

        if self.transform:
            image = self.transform(image)

# Set device
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Hyperparameters
in_channel = 3
num_classes = 2
learning_rate = 3e-4
batch_size = 32
num_epochs = 10

# Load Data
dataset = CatsAndDogsDataset(
    csv_file="/Users/vitamink/github_clone/BookNoteByChico/深度学习/pytorch-tutorial/Trail/cats_dogs.csv",
    root_dir="/Users/vitamink/github_clone/BookNoteByChico/深度学习/pytorch-tutorial/Trail/cats_dogs_resized",
    transform=transforms.ToTensor(),
)

# 划分数据集 可以用随机排列的生成器实现复用torch.Generator().manual_seed()
# [5, 5]表示一共有两行，每行有五个数据 也就是说train_set和test_set各五个数据
train_set, test_set = torch.utils.data.random_split(dataset, [5, 5])
train_loader = DataLoader(dataset=train_set, batch_size=batch_size, shuffle=True)
test_loader = DataLoader(dataset=test_set, batch_size=batch_size, shuffle=True)

# Model
# 关于googleNet
# googleNet的论文指出，获得更好的模型最保险的方法就是增加模型的深度，但是
# 更深或更宽的模型存在以下的问题:
# 参数多，过拟合
# 计算量大，难运用
# 梯度消失
# googleNet提出的解决方案是
# 将全连接层或者一般的卷积层都转化为稀疏连接，
# 原因是将稀疏矩阵聚类为比较密集的子矩阵可以提高计算性能
model = torchvision.models.googlenet(weights="DEFAULT")

# freeze all layers, change final linear layer with num_classes
for param in model.parameters():
    param.requires_grad = False

# final layer is not frozen
model.fc = nn.Linear(in_features=1024, out_features=num_classes)
model.to(device)
# Loss and optimizer
criterion = nn.CrossEntropyLoss()
# 提供模型中可优化的参数和学习率和
# weight_dacay调节模型的复杂度对损失函数的影响，防止过拟合
optimizer = optim.Adam(model.parameters(), lr=learning_rate, weight_decay=1e-5)

# Train Network
for epoch in range(num_epochs):
    losses = []

    for batch_idx, (data, targets) in enumerate(train_loader):
        # Get data to cuda if possible
        data = data.to(device=device)
        targets = targets.to(device=device)

        # forward
        # 前向传播求出预测的值
        scores = model(data)
        # 求出loss
        loss = criterion(scores, targets)

        # 因为pytorch的动态图求导机制是通过variable构建图
        # 如果使用varaible类型的loss，网络会延生变大消耗显存
        # loss.item()释放指向计算图形的指针
        losses.append(loss.item())

        # backward
        # 将loss关于weight的导数变为0
        # 每一轮batch需要清零梯度
        # 一个batch的loss关于weight的导数是所有sample的loss关于weight导数的累加和
        optimizer.zero_grad()
        # 反向传播求梯度
        loss.backward()

        # gradient descent or adam step
        # 更新所有参数
        optimizer.step()

    print(f"Cost at epoch {epoch} is {sum(losses)/len(losses)}")


# Check accuracy on training to see how good our model is
def check_accuracy(loader, model):
    num_correct = 0
    num_samples = 0
    model.eval()

    with torch.no_grad():
        for x, y in loader:
            x = x.to(device=device)
            y = y.to(device=device)

            scores = model(x)
            _, predictions = scores.max(1)
            num_correct += (predictions == y).sum()
            num_samples += predictions.size(0)

        print(
            f"Got {num_correct} / {num_samples} with accuracy {float(num_correct)/float(num_samples)*100:.2f}"
        )

    model.train()


print("Checking accuracy on Training Set")
check_accuracy(train_loader, model)

print("Checking accuracy on Test Set")
check_accuracy(test_loader, model) 
