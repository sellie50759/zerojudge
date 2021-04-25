
if __name__ == '__main__':
    t = int(input())
    while t:
        expr = input().split()
        left = int(expr[0])
        for i in range(1, len(expr), 2):
            if expr[i] == '+':
                left += int(expr[i + 1])
            elif expr[i] == '-':
                left -= int(expr[i + 1])
            elif expr[i] == '*':
                left *= int(expr[i + 1])
            elif expr[i] == '/':
                left //= int(expr[i + 1])
        if left > 9223372036854775807:#測資有問題
            left %= 9223372036854775808
        print(left)
        t -= 1
