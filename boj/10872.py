def fac(N):
    if N == 0:
        return 1
    else:
        return fac(N - 1) * N


N = int(input())

print(fac(N))
