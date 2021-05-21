modulo = []

for i in range(10):
    number = int(input()) % 42
    if number not in modulo:
        modulo.append(number)

print(len(modulo))
