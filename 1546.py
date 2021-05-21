N = int(input())
scores = input().split()
new_scores = 0
max = 0
for i in scores:
    if max < int(i):
        max = int(i)
for i in scores:
    new_score = int(i) / max * 100
    new_scores += new_score
print(new_scores / N)
