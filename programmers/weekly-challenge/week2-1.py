def solution(scores):
    answer = ''
    average = 0
    num = len(scores)

    s = [0 for i in range(num)]

    for i in range(num):
        for j in range(num):
            s[j] = scores[j][i]

        self_score = s[i]

        if s.count(self_score) == 1 and (self_score == max(s) or self_score == min(s)):
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
