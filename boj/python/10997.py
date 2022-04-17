def g(n):
    n = int(n)
    if n == 1:
        return ["*"]
    elif n == 2:
        return ["*****",
                "*    ",
                "* ***",
                "* * *",
                "* * *",
                "*   *",
                "*****"]
    else:
        ret = []
        prev = g(n-1)
        for i in range(4 * n - 1):
            if i == 0 or i == 4 * n - 2:
                ret.append("*" * (4 * n - 3))
            elif i == 1:
                ret.append("*" + " " * (4 * n - 4))
            elif i == 4 * n - 3:
                ret.append("*" + " " * (4 * n - 5) + "*")
            elif i == 2:
                ret.append("* " + prev[i-2] + "**")
            else:
                ret.append("* " + prev[i-2] + " *")
        return ret




num = int(input())
answer = g(num)
for i in range(len(answer)):
    if i == 1:
        print("*")
    else:
        print(answer[i])
