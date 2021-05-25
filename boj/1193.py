N = int(input())
n = 1
sum = 1
while N > sum:
    n += 1
    sum += n

if n % 2 == 0:
    boy = N - sum + n
    print(str(boy) + '/' + str(n + 1 - boy))
else:
    mom = N - sum + n
    print(str(n + 1 - mom) + '/' + str(mom))
