n1, n2 = input().split()

f1 = ''
f2 = ''

for i in n1:
    f1 = i + f1
for i in n2:
    f2 = i + f2
f1 = int(f1)
f2 = int(f2)

if f1 > f2:
    print(f1)
else:
    print(f2)
