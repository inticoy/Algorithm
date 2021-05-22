word = input()
place = []
sum = 0

for i in range(8):
    place.append(i + 2)
    place.append(i + 2)
    place.append(i + 2)
place.insert(15, 7)
place.append(9)

for i in word:
    index = ord(i) - 65
    sum += place[index] + 1
print(sum)
