"""
1. `len()` 查看训练、测试集长度
2. 训练次数
    200样本
    分为40批次
    每1批进行1次BP传播的参数更新 循环的次数iteration = 40
    40批走完为1个epoch 此时全部训练集参与完成了一次完整训练
    训练一共进行1000个epoch
3. `torch.save(net.state_dict(), "Net_{}.pth".format(i))` 模型保存
"""
# trainCIFAR.py
# from asyncore import write
import torchvision
from torch.utils.data import DataLoader
import torch
from torch import nn
import sys
import os
curPath = os.path.abspath(os.path.dirname("modelCIFAR.py"))
rootPath = os.path.split(curPath)[0]
sys.path.append(rootPath)
from modelCIFAR import Net
# from torch.utils.tensorboard import SummaryWriter  # 关于tensorboard的使用

# 训练数据集合测试数据集的准备
train_data = torchvision.datasets.CIFAR10(root = "../data", train=True, 
transform=torchvision.transforms.ToTensor(), download=True) # 注意要将PIL图像转换成向量

test_data = torchvision.datasets.CIFAR10(root="../data", train = False, 
transform=torchvision.transforms.ToTensor(), download=True)

# 查看训练数据集合测试数据集的长度
train_data_size = len(train_data)
test_data_size = len(test_data)

# format字符串格式化，format中的变量替换{}
print("训练数据集的长度为:{}".format(train_data_size))
print("训练数据集的长度为:{}".format(test_data_size))

# 利用Dataloader来加载数据集
# CIFAR10 60000 = 10 * 6000  32*32
# 一批64个sample
train_dataloader = DataLoader(train_data, batch_size=64)
test_dataloader = DataLoader(test_data, batch_size=64)

# 搭建神经网络(10分类)
net = Net()

# 创建交叉熵损失函数
loss_fn = nn.CrossEntropyLoss()

# 优化器 设置优化的参数和学习速率
learning_rate = 1e-2   # 0.01
# 随机梯度下降
optimizer = torch.optim.SGD(net.parameters(), lr=learning_rate)


# 设置训练网络的参数
# 记录训练的次数
total_train_step = 0
# 记录测试的次数
total_test_step = 0
# 所有数据训练的轮数
epoch = 10

# 添加tensorboard 绘制每次训练次数和误差
# writer = SummaryWriter("../logs_train")

for i in range(epoch):
    print("-----第{}轮训练开始-----".format(i+1)) # i从0 - 9 

    # 训练步骤开始
    for data in train_dataloader:
        imgs, targets = data
        outputs = net(imgs)
        loss = loss_fn(outputs, targets)

        # 优化器优化模型
        optimizer.zero_grad() # 用优化器清零梯度
        loss.backward()  # 得到每个参数节点的梯度
        optimizer.step()

        total_train_step = total_train_step+1  # 训练完一次

        if total_train_step % 100 == 0:
            print("训练次数:{}, loss: {}".format(total_train_step, loss.item())) # item将tensor数据类型转换成数字
            # writer.add_scalar("train_loss", loss.item(), total_train_step)


    # 每次训练完一轮以后，在测试数据集上跑一遍，用测试数据集上的损失或者叫正确率来评估有没有训练好
    
    
    # 求和每次一部分的loss
    total_test_loss = 0
    total_accuracy = 0
    
    # 测试步骤开始
    with torch.no_grad(): # 没有梯度，保证不会调优网络的参数
        for data in test_dataloader:  # data的一部分数据在网络模型上的损失
            imgs, targets = data
            # 只是相同通过该网络算出误差，不需要调优
            outputs = net(imgs)
            loss = loss_fn(outputs, targets) # tensor数据类型
            total_test_loss += loss.item()  # loss是一个张量转换成item标量
            accuracy = (outputs.argmax(1) == targets).sum() # 统计预测正确的训练样本的数量  1是横向比feature概率
            total_accuracy += accuracy

    print("整体测试集上的loss: {}".format(total_test_loss))  
    print("整体测试集上的正确率: {}".format(total_accuracy / test_data_size))  # 正确率 = 预测正确的个数 / 总个数

    # writer.add_scalar("test_loss", total_test_loss, total_test_step)
    # writer.add_scalar("test_accuracy", total_accuracy/test_data_size, total_test_step)
    # total_test_step += 1  # 测试完一次就需要将step+1 不然无法绘制图形

    # torch.save(net, "Net_{}.pth".format(i))
    # 官方推荐的保存模型
    torch.save(net.state_dict(), "Net_{}.pth".format(i))
    print("模型已保存")


# writer.close()

