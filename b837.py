if __name__ == '__main__':
    fib=[0,1]
    while(fib[-1]<=1000000):
        fib.append(fib[-1]+fib[-2])
    t=int(input())
    while t:
        a,b=map(int,input().split())
        ans=0
        if(b<a):
            a,b=b,a
        for i in fib:
            if(i>=a and i<=b):
                print(i)
                ans+=1
        print(ans)
        if(t !=1):
            print("------")
        t-=1
