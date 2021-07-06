A = int(input())
B = int(input())
C = int(input())
result = str(A * B * C)
result_list = []
for i in range(10):
    result_list.append(0)
for i in range(len(result)):
    result_list[int(result[i])] += 1
for i in result_list:
    print(i)
