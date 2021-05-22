word = input()
place = []
for i in range(26):
    place.append(-1)

for i in range(len(word)):
    ascii = ord(word[i])
    if place[ascii - 97] == -1:
        place[ascii - 97] = i

for i in place:
    print(i, end=' ')
