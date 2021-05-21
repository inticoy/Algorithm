N = int(input())
line = input().split()
number = []


for i in line:
    number.append(int(i))

number_unique = [number[0]]
for i in number:
    if i not in number_unique:
        for j in range(len(number_unique)):
            if number_unique[j] < i:
                 number_unique.insert(j, i)

print(number_unique)
#
# for i in number:
#     print(number_unique.index(i), end=' ')
