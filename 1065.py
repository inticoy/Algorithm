def isSequence(n):
    str_n = str(n)
    list_n = []
    for letter in str_n:
        list_n.append(int(letter))

    if len(list_n) == 1:
        difference = 0
    else:
        difference = list_n[1] - list_n[0]

    for i in range(len(list_n) -1):
        if (list_n[i+1] - list_n[i]) != difference:
            return False
    return True


N = int(input())
count = 0
for i in range(1, N+1):
    if isSequence(i):
        count += 1
print(count)
