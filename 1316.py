def isGroup(text):
    list_text = [text[0]]
    for i in range(1, len(text)):
        if text[i] != list_text[-1]:
            list_text.append(text[i])
    for number in list_text:
        if list_text.count(number) != 1:
            return False
    return True

N = int(input())
count = 0
for time in range(N):
    line = input()
    if isGroup(line):
        count += 1
print(count)
