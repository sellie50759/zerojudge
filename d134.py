def C(n,m):
    ans=1
    for i in range(n-m+1,n+1):
        ans*=i

    for i in range(2,m+1):
        ans//=i
    return ans
if __name__ == '__main__':
    while 1:
        try:
            n,m=map(int,input().split())
        except EOFError:
            break
        if(n==0 and m==0):
            break
        print("%d things taken %d at a time is %d exactly."%(n,m,C(n,m)))
