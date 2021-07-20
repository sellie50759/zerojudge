if __name__ == '__main__':
    while 1:
        try:
            n = input()
        except EOFError:
            break
        n = n.replace('RED', '0')
        n = n.replace('GREEN', '0')
        ans = 1
        for i in n:
            if i == '0':
                ans <<= 1
        print('1/%d' % ans)
