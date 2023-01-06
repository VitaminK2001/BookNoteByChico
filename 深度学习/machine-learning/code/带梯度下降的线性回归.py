"""
Implementation of Linear Regression using Gradient Descent.

Let m = #training examples, n = #number of features Sizes differ 
a little bit from blog notation. It takes as input the following: 
y is R^(1 x m), X is R^(n x m), w is R^(n x 1)

Programmed by chico
*    2020-04-03 Initial coding
*    2020-04-25 Updated comments, and small changes in code
"""

import numpy as np


class LinearRegression:
    def __init__(self, print_cost=True):
        self.learning_rate = 0.01
        self.total_iterations = 1000
        self.print_cost = print_cost

    def y_hat(self, X, w):
        # w是n行一列 转置后是一行n列，刚好和n行的X点积 算出 每一个特征值的预测值后求和
        return np.dot(w.T, X)  

    def cost(self, yhat, y):
        # 损失函数采用均方误差
        C = 1 / self.m * np.sum(np.power(yhat - y, 2))

        return C

    def gradient_descent(self, w, X, y, yhat):
        # T表示转置 dot点积直接求和 dCdW表示对w求偏导
        dCdW = 1 / self.m * np.dot(X, (yhat - y).T)  
        w = w - self.learning_rate * dCdW

        return w

    def main(self, X, y):  # y = w1 + w2x2 + w3x3 + ...  ∵ x1 = 1所以w1 是 b
        # Add x1 = 1
        ones = np.ones((1, X.shape[1])) # x1在每一列的值都是1
        X = np.append(ones, X, axis=0) # 行拼接

        self.m = X.shape[1]  # 列 特征值数量
        self.n = X.shape[0]  # 行 训练样本数量

        w = np.zeros((self.n, 1))  # n行1列 w在每一行都是0

        for it in range(self.total_iterations + 1):
            yhat = self.y_hat(X, w) # 预测值
            cost = self.cost(yhat, y) # 损失

            if it % 100 == 0 and self.print_cost:
                print(f"Cost at iteration {it} is {cost}") # 打印损失

            w = self.gradient_descent(w, X, y, yhat)

        return w


if __name__ == "__main__":
    X = np.random.rand(1, 500) # 样本点
    y = 3 * X + 5 + np.random.randn(1, 500) * 0.1  # 实际值
    regression = LinearRegression() 
    w = regression.main(X, y) # 学习w
    print(w)