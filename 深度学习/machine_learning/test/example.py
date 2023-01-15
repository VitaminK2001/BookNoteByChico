import numpy as np
from sklearn.datasets import make_blobs

if __name__ == "__main__":
    print(np.ones(5))
    print(range(4))
    for i in range(4):
        print(i)
        i += 1
    
    a = np.array([[1, 3, 4]])
    b = np.array([[2, 1, 1]])
    print(a)
    print(np.dot(b, a.T))
    c = np.array([[3, 2],[1,5]])
    d = np.array([[4, 1],[2,7]])
    print((d-c).T.shape)
    print((d-c).T) # T表示对ndarray进行转置
    print((d-c))

    e = np.append(a, b, axis = 1) # 如果axis = 1表示在列上拼接 
    print(e)
    print(e.shape) # 列拼接(1, 6) 行拼接(2, 3)

    print(np.random.randn(1, 20))

    X, y = make_blobs(n_samples=1000, centers=2)
    print(X)
