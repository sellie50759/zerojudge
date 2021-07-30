if __name__ == '__main__':
    n,m=map(int,input().split())
    section = [False]*(n+1)
    cmd = []
    while m:
        a,b = map(int,input().split())
        section[a] = True
        cmd.append((a,b))
        m-=1
    ismove = True
    while ismove:
        ismove = False
        for c in cmd:
            if not section[c[1]]:
                section[c[1]] = True
                section[c[0]] = False
                ismove = True
                cmd.remove(c)
            elif c[0] == c[1]:
                ismove = True
                cmd.remove(c)
    if cmd:
        print("Yes")
    else:
        print("No")
