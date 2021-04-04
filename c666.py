import sys
notprime=[False]*50000
notprime[0]=True
notprime[1]=True
prime=[]
def init():
    global notprime,prime
    for i in range(2,48612):
        if(notprime[i]==False):
            prime.append(i)
            j=2
            while(i*j<48612):
                notprime[i*j]=True
                j+=1
init()
ans=[1]
for i in prime:
    ans.append(ans[-1]*i)
for line in sys.stdin:
    print(ans[int(line)])
