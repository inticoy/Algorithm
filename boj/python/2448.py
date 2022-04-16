from sys import stdin

def star(num:int):
    num = int(num)
    if num == 3:
        return ['  *  ',
                ' * * ',
                '*****']
    else:
        ret = []
        prev = star(num/2)
        for i in range(num):
            if i < num/2:
                ret.append(' ' * (num//2) + prev[i] + ' ' * (num//2))
            else:
                ret.append(prev[i - num//2] + ' ' + prev[i - num//2])
        return ret


height = int(stdin.readline())
answer = star(height)
string_answer = ''
for i in answer:
    string_answer += i + '\n'

print(string_answer)
