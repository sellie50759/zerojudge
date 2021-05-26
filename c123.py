def main():
    while 1:
        n = int(input())
        if n == 0:
            break
        while 1:
            m = tuple(map(int, input().split()))
            if m[0] == 0:
                break
            stack = []
            i = 1
            error = False
            for j in m:
                if i <= j:
                    while i != j+1:
                        stack.append(i)
                        i += 1
                    stack.pop()
                elif i > j:
                    if j != stack[-1]:
                        error = True
                        break
                    else:
                        stack.pop()
            if error:
                print("No")
            else:
                print("Yes")


if __name__ == '__main__':
    main()
