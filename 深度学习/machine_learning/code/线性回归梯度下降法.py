import numpy as np

class LinearRegression:
    def __init__(self, print_cost=True):
        self.learning_rate = 0.01
        self.total_iterations = 1000
        self.print_cost = print_cost

    def y_hat(self, X, w):
        # w是n行一列 转置后是一行n列，刚好和n行m列的X点积 算出 每一个特征值的预测值后求和
        return np.dot(w.T, X)  

    def cost(self, yhat, y):
        # 损失函数采用均方误差
        C = 1 / self.m * np.sum(np.power(yhat - y, 2))
        return C

    def gradient_descent(self, w, X, y, yhat):
        # T表示转置 X是n行m列的向量 yhat-y 是 m行n列的向量
        # 最后的点积是n个sample的偏导和
        # dCdW表示C对w求偏导
        dCdW = 1 / self.m * np.dot(X, (yhat - y).T)  
        w = w - self.learning_rate * dCdW

        return w

    def main(self, X, y): 
        # Add x1 = 1
        """
        X本来只有一行,列数是sample的总数
        w的行数和X的列数保持一致
        现在X多添加一行全为1 w变成两行
        对于每一个sample和w点积后
        y_hat = w1 * x1 + x2 * w2 因为x2总是1 所以w2 充当b
        """
        ones = np.ones((1, X.shape[1])) # 相当于对于每个sample 都要加一项 x * w2 = w2 = b
        X = np.append(ones, X, axis=0) # axis = 0行拼接 X从一行（一元）变成两行

        self.m = X.shape[1]  # 训练样本数量
        self.n = X.shape[0]  # 特征值数量（几元）

        w = np.zeros((self.n, 1))  # n行1列 w在每一行都是0

        for it in range(self.total_iterations + 1):
            yhat = self.y_hat(X, w) # 预测值
            cost = self.cost(yhat, y) # 损失

            if it % 100 == 0 and self.print_cost:
                print(f"Cost at iteration {it} is {cost}") # 打印损失

            w = self.gradient_descent(w, X, y, yhat)

        return w


if __name__ == "__main__":
    X = np.random.rand(1, 500) # 样本点 一元变量的sample数量500个
    y = 3 * X + 5
    # y = 3 * X + 5 + np.random.randn(1, 500) * 0.1  # 希望样本更加分散一点可以考虑正则化
    regression = LinearRegression() 
    w = regression.main(X, y) # 学习w
    print(w)