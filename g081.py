if __name__ == '__main__':
    n,m,l = map(int,input().split())
    cmd = []
    while n:
        cmd.append(tuple(map(int,input().split())))
        n-=1
    l-=1
    now = list(map(int,input().split()))
    while l:
        next = list(map(int,input().split()))
        temp = []
        for i in range(m):
            temp.append(next[i]-now[i])
        print(cmd.index(tuple(temp))+1)
        now = next
        l-=1
