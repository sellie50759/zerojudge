import copy

if __name__ == '__main__':
    dir = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]
    n = int(input())
    temp = [0] * (n + 2)
    map = []
    for i in range(n + 2):#二維array要deep copy 不然每一row的值都會一樣
        map.append(copy.deepcopy(temp))
    for i in range(1, n + 1):
        row = input()
        j = 1
        for token in row:
            if token == '*':
                map[i][j] = -9
                for k in dir:
                    map[i + k[0]][j + k[1]] += 1
            j += 1
    for i in range(1, n + 1):
        ans = ""
        for j in range(1, n + 1):
            if map[i][j] < 0:
                ans += '*'
            elif map[i][j] > 0:
                ans += str(map[i][j])
            else:
                ans += '-'
        print(ans)
