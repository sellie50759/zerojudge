from sys import stdin

if __name__ == '__main__':
    for line in stdin:
        row = ""
        column = ""
        for i in range(len(line)):
            if line[i].isdigit():
                row = line[0:i]
                column = line[i:]
                break
        j = 1
        sum = 0
        for i in range(1, len(row) + 1):
            sum += (ord(row[-i]) - ord('A')+1) * j
            j *= 26
        column = int(column)
        print(column * sum)
