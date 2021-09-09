def solution(scores):
    answer = ''
    average = 0
    num = len(scores)
    _scores = [[0 for j in range(num)] for i in range(num)]
    for i in range(num):
        for j in range(num):
            _scores[i][j] = scores[j][i]

    for i, s in enumerate(_scores):
        self_score = s[i]
        if (self_score == max(s) and s.count(self_score) == 1) or (self_score == min(s) and s.count(self_score) == 1):
            average = (sum(s) - self_score) / (num - 1)
        else:
            average = sum(s) / num
        if average >= 90:
            answer += 'A'
        elif average >= 80:
            answer += 'B'
        elif average >= 70:
            answer += 'C'
        elif average >= 50:
            answer += 'D'
        else:
            answer += 'F'

        average = 0

    return answer
