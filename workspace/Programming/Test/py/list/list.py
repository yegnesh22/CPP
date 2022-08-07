myList = [0, 1]

def fn1():
    for i in myList:
        print(i)


def main():
    fn1()
    myList[0]=1
    myList[1]=2
    myList.append(3)
    fn1()
    myList.pop()
    fn1()

if __name__ == "__main__":
    main()


