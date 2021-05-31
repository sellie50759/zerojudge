pag=['1','2','3']
step=0
t=0
def hanoi(n,start,end):
    global pag,t,step
    if(n==1):
        step+=1
        if(step==t):
            print("move %d from %s to %s"%(n,start,end))
        return
    else:
        if(step>t):
            return
        other=""
        for i in pag:
            if(i !=start and i !=end):
                other=i
                break
        #print((1<<(n-1))-1)
        if(step+(1<<(n-1))-1<t):
            step+=(1<<(n-1))-1
        else:
            hanoi(n-1,start,i)
        step+=1
        if (step == t):
            print("move %d from %s to %s" % (n, start, end))
            return
        if (step+(1 << (n-1))-1 < t):
            step += (1 << (n-1))-1
        else:
            hanoi(n - 1, i, end)

if __name__ == '__main__':
    while 1:
        try:
            n,i=map(int,input().split())
        except EOFError:
            break
        t=i
        step=0
        hanoi(n,'1','3')
