# modelCIFAR.py
import torch
from torch import nn

"""
模型
1. 对于深度神经网络可以用`nn.Sequential()` 避免在forward中重复写

2. 验证正确性 给定输入查看输出的尺寸
"""

# 从网上找的网络模型
class Net(nn.Module):
    # 构建网络模型首先是init和forward
    def __init__(self) -> None:
        super(Net, self).__init__()
        # 避免在forward中写一长串
        self.module = nn.Sequential(
            nn.Conv2d(3, 32, 5, 1, 2), # kernelsize: 5  padding:（32 - (32-5+1)) / 2 = 2
            nn.MaxPool2d(2),  # kernelsize : 2    32 / 16 = 2 (input channel / output channel)
            nn.Conv2d(32, 32, 5, 1, 2),
            nn.MaxPool2d(2),
            nn.Conv2d(32, 64, 5, 1, 2),
            nn.MaxPool2d(2),
            nn.Flatten(),
            nn.Linear(64*4*4, 64), # 64层 4x4的图片展平后的像素个数 要变成64个1x1的像素点
            nn.Linear(64, 10)
        ) 
    
    def forward(self, x):
        x = self.module(x)
        return x

if __name__ == '__main__':
    net = Net()
    # 验证网络模型的正确性，给定一个输入的尺寸，查看输出的尺寸是否正确
    input = torch.ones((64,3,32,32))
    output = net(input)
    print(output.size())