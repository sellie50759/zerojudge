import bisect


def LIS(nums):
    tail = []
    for num in nums:
        pos = bisect.bisect_left(tail, num+1, lo=0, hi=len(tail))
        if pos == len(tail):
            tail.append(num)
        else:
            tail[pos] = num
    return len(tail)


while 1:
    try:
        n = int(input())
    except EOFError:
        break
    arr = tuple(map(int, input().split()))
    print(len(arr)-LIS(arr))
'''
經過詳細的觀察之後可以知道答案等於arr的長度減去arr的LIS的長度
因為題目要求的是將arr變成非嚴格遞增的序列，只要有在arr的LIS裡的數都不需要被變化，
只需要將在LIS以外的數都變成最接近的在LIS裡的數，整個arr就會是非嚴格遞增。
例如題目的第二筆測資: 
[4, 1, 5, 2, 6, 2]
其中一種LIS的序列是[1, 2, 6]，所以把除了[1, 2, 6]的其他數都變為最接近的LIS裡的數,所以arr[0]變成1,arr[2]變成2,arr[5]變成6
arr從[4, 1, 5, 2, 6, 2]->[1, 1, 2, 2, 6, 6]
就達成最少步驟的變法，而步驟數就等於arr的長度減去arr的LIS的長度
'''
