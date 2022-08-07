# Program to do Matrix operations add, subtract and multiply

def MatAdd(X, Y):
    result = []
    for i in range(len(X)):
        r = []
        for j in range(len(X[i])):
            r.append(X[i][j] + Y[i][j])
        result.append(r)
    return result

def MatSub(X, Y):
    result = []
    for i in range(len(X)):
        r = []
        for j in range(len(X[i])):
            r.append(X[i][j] - Y[i][j])
        result.append(r)
        return result

def MatMul(X, Y):
    result = []
    for i in range(len(X)):
        r = []
        for j in range(len(Y[0])):
            s = 0
            for k in range(len(Y)):
                s += X[i][k] * Y[k][j]
            r.append(s)
        result.append(r)
    return result

def main():
    X = [[12,7,3], [4 ,5,6], [7 ,8,9]]
    Y = [[5,8,1], [6,7,3], [4,5,9]]
    print(X)
    print(Y)
    print(MatAdd(X, Y))
    print(MatSub(X, Y))
    print(MatMul(X, Y))


if __name__ == "__main__":
    main()
