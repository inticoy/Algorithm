def solution(word):
    n = len(word)
    word2num = 0
    answer = 0


    l = [781, 156, 31, 6, 1]
    d = {'A':0, 'E':1, 'I':2, 'O':3, 'U':4}
    for i, j in enumerate(word):
        answer += l[i] * d[j]
    answer += 1
    return answer
