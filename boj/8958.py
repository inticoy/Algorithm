time = int(input())

for i in range(time):
    line = input()
    combo = 1
    score = 0
    for j in line:
        if j == 'O':
            score += combo
            combo += 1
        else:
            combo = 1
    print(score)
