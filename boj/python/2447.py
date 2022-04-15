def star(num:int, blank:bool):
    num = int(num)
    if blank:
        return [[' ' for i in range(num)] for j in range(num)]
    if num == 3:
        return [['*', '*', '*'], ['*', ' ', '*'], ['*', '*', '*']]
    else:
        lst = []
        frame = star(num/3, False)
        center = star(num/3, True)
        for i in range(num):
            if int(i / (num/3)) == 1:
                lst.append(frame[int(i % (num/3))] + center[int(i % (num/3))] + frame[int(i % (num/3))])
            else :
                lst.append(frame[int(i % (num/3))] * 3)
        return lst


n = int(input())
get_star = star(n, False)
for i in get_star:
    for j in i:
        print(j, end="")
    print()
