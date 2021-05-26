if __name__ == '__main__':
    n = int(input())
    point = []
    while n:
        point.append(tuple(map(int, input().split())))
        n -= 1
    point.sort()
    for i in point:
        print("%d %d" % (i[0], i[1]))
