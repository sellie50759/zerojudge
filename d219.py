if __name__ == '__main__':
    while 1:
        try:
            B,P,M=map(int,input().split())
        except EOFError:
            break
        base=B
        ans=1
        while(P):
            if(P&1):
                ans*=base
                ans%=M
            base=base*base%M
            P>>=1
        print(ans)
