if __name__ == '__main__':
    t = int(input())
    while t:
        print(eval(input().replace('/', '//')))
        t -= 1
