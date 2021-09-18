def solution(word):
    n = len(word)
    word2num = 0

    d = {'A': 1, 'E': 2, 'I': 3, 'O': 4, 'U': 5}
    for i, j in enumerate(word):
        word2num += d[j] * (10 ** (-1 * i))

    return word2num
