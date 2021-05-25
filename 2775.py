def people(floor, room):
    sum = 0
    if floor == 0:
        sum += room
    else:
        for i in range(room):
            sum += people(floor - 1, i + 1)
    return sum


test = int(input())

for i in range(test):
    k = int(input())
    n = int(input())
    print(people(k, n))
