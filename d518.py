def main():
    while 1:
        try:
            n = int(input())
        except EOFError:
            break
        table = {}
        now = 1
        while n:
            temp = input()
            if temp in table:
                print("Old! %d" % table[temp])
            else:
                print("New! %d" % now)
                table[temp] = now
                now += 1
            n -= 1


if __name__ == '__main__':
    main()
