P = int(input())

for times in range(P):
    line = input().split()
    n = int(line[0])
    word = line[1]
    new_word = ""
    for i in word:
        new_word += i * n
    print(new_word)
