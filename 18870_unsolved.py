import sys
N = int(input())
line = sys.stdin.readline().split()


numbers = [int(line[0])]
for i in line:
    if int(i) not in numbers:
        numbers.append(int(i))

numbers.sort()
for i in line:
    print(numbers.index(int(i)), end=' ')
