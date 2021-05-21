def d(n):
    ret = n
    str_n = str(n)
    for i in str_n:
        ret += int(i)
    return ret

not_self = []

for i in range(1, 10000):
    n = i
    while n < 10000:
        n = d(n)
        #print(n)
        if n in not_self:
            break
        else:
            not_self.append(n)

for i in range(1, 10000):
    if i not in not_self:
        print(i)
