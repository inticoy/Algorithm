import sys
T = int(input())

for time in range(T):
    line = sys.stdin.readline().rstrip().split()
    print(int(line[0]) + int(line[1]))
