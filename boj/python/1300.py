N = int(input())
k = int(input())

B = []
for i in range(1, N + 1):
    for j in range(1, N + 1):
        B.append(i * j)
B.sort()

print(B[k - 1])
