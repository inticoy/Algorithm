C = int(input())

for case in range(C):
    line = input().split()
    N = int(line[0])
    sum = 0
    above = 0
    for score in line[1:]:
        sum += int(score)
    average = float(sum) / N
    for score in line[1:]:
        if average < int(score):
            above += 1
    print('%.3f' % (above / N * 100) + '%')
