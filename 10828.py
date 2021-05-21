import sys


def push(stack, X):
    stack.append(X)
    return stack


def pop(stack):
    if len(stack) == 0:
        return [], -1
    else:
        return stack[:-1], stack[-1]


def size(stack):
    return len(stack)


def empty(stack):
    if len(stack) == 0:
        return 1
    else:
        return 0


def top(stack):
    if len(stack) == 0:
        return -1
    else:
        return stack[-1]


stack = []
N = int(input())

for i in range(N):
    line = sys.stdin.readline()
    if line[:2] == "pu":
        number = line.split()[1]
        stack = push(stack, number)
    elif line[:2] == "po":
        stack, number = pop(stack)
        print(number)
    elif line[:2] == "si":
        print(size(stack))
    elif line[:2] == "em":
        print(empty(stack))
    elif line[:2] == "to":
        print(top(stack))
