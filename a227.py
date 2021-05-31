pag=['A','B','C']
def hanoi(n,start,end):
    global pag
    if(n==1):
        print("Move ring %d from %s to %s"%(n,start,end))
        return
    else:
        other=""
        for i in pag:
            if(i !=start and i !=end):
                other=i
                break
        hanoi(n-1,start,i)
        print("Move ring %d from %s to %s" % (n, start, end))
        hanoi(n-1,i,end)

if __name__ == '__main__':
    while 1:
        try:
            n=int(input())
        except EOFError:
            break
        hanoi(n,'A','C')
