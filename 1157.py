count = []
for i in range(26):
    count.append(0)

word = input().upper()
for i in word:
    ascii = ord(i)
    index = ascii - 65
    count[index] += 1

if count.count(max(count)) > 1:
    print("?")
else:
    print(chr(count.index(max(count)) + 65))
