# 테스트 1 〉	통과 (0.01ms, 10.2MB)
# 테스트 2 〉	통과 (0.02ms, 10.2MB)
# 테스트 3 〉	통과 (0.01ms, 10.2MB)
# 테스트 4 〉	통과 (0.01ms, 10.2MB)
# 테스트 5 〉	통과 (0.01ms, 10.2MB)
# 테스트 6 〉	통과 (0.03ms, 10.2MB)
# 테스트 7 〉	통과 (0.02ms, 10.3MB)
# 테스트 8 〉	통과 (0.02ms, 10.3MB)
# 테스트 9 〉	통과 (0.02ms, 10.2MB)
# 테스트 10 〉	통과 (0.04ms, 10.2MB)
# 테스트 11 〉	통과 (0.01ms, 10.1MB)
# 테스트 12 〉	통과 (0.01ms, 10.2MB)
# 테스트 13 〉	통과 (0.01ms, 10.2MB)
# 테스트 14 〉	통과 (0.01ms, 10.1MB)
# 테스트 15 〉	통과 (0.02ms, 10.2MB)
# 테스트 16 〉	통과 (0.02ms, 10.2MB)
# 테스트 17 〉	통과 (0.02ms, 10.3MB)
# 테스트 18 〉	통과 (0.02ms, 10.2MB)
# 테스트 19 〉	통과 (0.02ms, 10.2MB)
# 테스트 20 〉	통과 (0.02ms, 10.2MB)
# 테스트 21 〉	통과 (0.01ms, 10.3MB)

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
