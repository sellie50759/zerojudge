from itertools import permutations
if __name__ == '__main__':
    while 1:
        try:
            n=int(input())
        except EOFError:
            break
        for i in permutations(range(1,n+1),n):
            print(" ".join(map(str,i)))
