word = input()
count = 0
CROATIAN = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for i in CROATIAN:
    count += word.count(i)
    word = word.replace(i, ' ')
for i in word:
    if i != ' ':
        count += 1

print(count)
