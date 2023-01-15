import numpy as np
from sklearn.datasets import make_blobs

class LogisticRegression:
    def __init__(self, X, learning_rate=0.1, num_iters=10000):
        self.lr = learning_rate
        self.num_iters = num_iters

        # m for sample  n for label
        self.m, self.n = X.shape

    def train(self, X, y):
        # init weights
        self.weights = np.zeros((self.n, 1))
        self.bias = 0

        for it in range(self.num_iters + 1):
            # calculate hypothesis
            y_predict = self.sigmoid(np.dot(X, self.weights) + self.bias)

            # calculate cost
            cost = (
                -1 / self.m
                * np.sum(y * np.log(y_predict) + (1 - y) * np.log(1 - y_predict))
            )

            # back prop / gradient calculations
            dw = 1 / self.m * np.dot(X.T, (y_predict - y))
            db = 1 / self.m * np.sum(y_predict - y)

            # gradient descent update step
            self.weights -= self.lr * dw
            self.bias -= self.lr * db

            # print cost sometimes
            if it % 1000 == 0:
                print(f"Cost after iteration {it}: {cost}")

        return self.weights, self.bias

    def predict(self, X):
        # X m行 n列      weights n行 1列
        y_predict = self.sigmoid(np.dot(X, self.weights) + self.bias) # w·x + b
        y_predict_labels = y_predict > 0.5

        return y_predict_labels

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))


if __name__ == "__main__":
    np.random.seed(1)
    # X是样本 y是标签
    # center是每个cluster的标签数量
    X, y = make_blobs(n_samples=1000, centers=2) # 生成数据集 center是label的数量 n_samples是训练样本的数量
    # np.newaxis表示增加y的维度     放在:后面增加列数，放在:前面增加行数
    y = y[:, np.newaxis]

    logreg = LogisticRegression(X)
    w, b = logreg.train(X, y)
    y_predict = logreg.predict(X)

    print(f"Accuracy: {np.sum(y==y_predict)/X.shape[0]}")