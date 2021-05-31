def f(x):
    if(x==1):
        return 1
    elif(x&1):
        return f(x-1)+f(x+1)
    else:
        return f(x//2)
if __name__ == '__main__':
    print(f(int(input())))
