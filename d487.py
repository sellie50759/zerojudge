def fac(x):
    if(x==0):
        print("%d = " % (x+1), end="")
        return 1;
    else:
        if(x !=1):
            print("%d * "%x,end="")
        return x*fac(x-1)
if __name__ == '__main__':
    while 1:
        try:
            n=int(input())
        except EOFError:
            break
        print("%d! = "%n,end="")
        print(fac(n))
