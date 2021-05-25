line1 = input().split()
N = int(line1[0])
X = int(line1[1])


line2 = input().split()

for i in range(N):
    if X > int(line2[i]):
        print(line2[i], end=' ')
