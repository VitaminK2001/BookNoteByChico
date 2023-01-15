"""
测试
1. `transforms.Compose()` 融合多种变形器

2. `model = torch.load("模型位置", map_location=torch.device("cpu"))` 

3. `model.eval()`对于含有dropout层或者batchnorm层有用 其它层无用
    在train模式下 dropout网络层会按照设定的参数p设置保留激活单元的概率 保留概率=p; 
    batchnorm层会继续计算数据的mean和var等参数并更新
    在val模式下 dropout层会让所有的激活单元都通过 
    而batchnorm层会停止计算和更新mean和var 直接使用在训练阶段已经学出的mean和var值。
    1. dropout层理解
        [dropout](https://www.notion.so/dropout-2fb82f18ea214d6c8d886dce989806c5)
    2. batchnorm层理解 [https://www.notion.so/cqg-stack/T2001-9-23-a771b1b9a77940bcbdd9bfe181902587#0b70030a106a4bef9c9ba366d9b14245](https://www.notion.so/T2001-9-23-a771b1b9a77940bcbdd9bfe181902587)
4. `torch.no_grad()`关闭自动求导引擎 
"""

# testCIFAR.py
from statistics import mode
from PIL import Image
import torchvision
import torch
from torch import nn

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

img_path = "/Users/vitamink/github_clone/BookNoteByChico/深度学习/pytorch_tutorial/cifar/pic/airplane.png"
image = Image.open(img_path)
image = image.convert('RGB') # png格式是四个通道，除了RGB还有一个透明度，如果图面便来就是三通道经过此操作后是不会改变的
print(image)

transfrom = torchvision.transforms.Compose([torchvision.transforms.Resize((32,32)),
                                            torchvision.transforms.ToTensor()])  # Composes several transforms together

image = transfrom(image).to(device)

print(image.shape)  # 本身的size还是492x324 但是转换成的tensor变成32x32


class Net(nn.Module):
    def __init__(self) -> None:
        super(Net, self).__init__()
        self.module = nn.Sequential(
            nn.Conv2d(3, 32, 5, 1, 2),
            nn.MaxPool2d(2),  # 池化的过程
            nn.Conv2d(32, 32, 5, 1, 2),
            nn.MaxPool2d(2),
            nn.Conv2d(32, 64, 5, 1, 2),
            nn.MaxPool2d(2),
            nn.Flatten(),
            nn.Linear(64*4*4, 64),
            nn.Linear(64, 10)
        ) 
    
    def forward(self, x):
        x = self.module(x)
        return x

# model = torch.load("模型位置", map_location=torch.device("cpu")) 如果在GPU上训练的模型单纯只是想在CPU上跑，需要写这条语句转换位置

model = Net()
model = model.to(device)
model.load_state_dict(torch.load("/Users/vitamink/github_clone/BookNoteByChico/深度学习/pytorch_tutorial/cifar/Net_9.pth"))

# 打印模型
print(model)

image = torch.reshape(image, (1,3,32,32))
model.eval()
with torch.no_grad():
    output = model(image)
print(output)

# CIFAR-10是一个常用的彩色图片数据集，它有10个类别: 
# ‘airplane’, ‘automobile’, ‘bird’, ‘cat’, ‘deer’, ‘dog’, ‘frog’, ‘horse’, ‘ship’, ‘truck’。

# 打印出测试的结果
print(output.argmax(1).item()) # 0纵向比较  1横向比较