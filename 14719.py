line = input().split()
H = int(line[0])
W = int(line[1])

line = input().split()

for i in range(len(line)):
    line[i] = int(line[i])

sum = H * W - sum(line)

print(sum)
