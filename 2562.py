count = 0
max = 0
for i in range(1, 10):
    number = int(input())
    if(max < number):
        max = number
        count = i
print(max)
print(count)
