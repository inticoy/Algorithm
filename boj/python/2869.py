import math
line = input().split()
A = int(line[0])
B = int(line[1])
V = int(line[2])


i = math.ceil((V - A) / (A - B)) + 1
print(i)
