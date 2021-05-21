N = input()
original = int(N)
count = 0
while True:
    if len(N) == 1:
        N = '0'+N
    N = N[-1]+ str(int(N[0]) + int(N[-1]))[-1]
    count += 1
    if int(N) == original:
        break
print(count)
