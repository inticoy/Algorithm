def square(n):
    n = int(n)
    if n == 1:
        return ["*"]
    else:
        ret = []
        prev = square(n-1)
        for i in range(4 * n - 3):
            if (i == 0 or i == 4 * n - 4):
                ret.append('*' * (4 * n - 3))
            elif (i == 1 or i == 4 * n - 5):
                ret.append('*' + ' ' * (4 * n - 5) + '*')
            else:
                ret.append('* ' + prev[i-2] + ' *')
        return ret

num = int(input())
answer = square(num)
for i in answer:
    print(i)
