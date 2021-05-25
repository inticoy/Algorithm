T = int(input())

for time in range(T):
    line = input().split()
    A = int(line[0])
    B = int(line[1])
    print('Case #' + str(time + 1) + ': ' + str(A + B))
