import math
nums = input().split()

min = int(nums[0])
max = int(nums[1])
isSqr = []
for i in range(min, max + 1):
    isSqr.append(0)


sqr = []
sqrt = int(math.sqrt(max)) + 1
for i in range(2, sqrt):
    sqr.append(i * i)


for i in sqr:
    start = i * (int(min / i) + 1)
    print(start)
    for j in range(start, max + 1, i):
        isSqr[j - min] = 1

print(isSqr.count(0))
