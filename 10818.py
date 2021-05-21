N = int(input())
numbers = input().split()
min = int(numbers[0])
max = int(numbers[0])

for number in numbers:
    if min > int(number):
        min = int(number)
    if max < int(number):
        max = int(number)

print(min, max)
