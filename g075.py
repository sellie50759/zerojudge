if __name__ == '__main__':
    l = input().split()
    n = int(l[0])
    k = float(l[1])
    sum = 0
    while n:
        sum += float(input())
        n -= 1
    print(int(sum//k)+1)
