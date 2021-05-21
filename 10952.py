while True:
    line = input().split()
    A = int(line[0])
    B = int(line[1])
    if A==0 and B==0:
        break
    print(A+B)
