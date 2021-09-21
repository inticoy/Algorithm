def solution(table, languages, preference):
    table = [i.split(" ") for i in table]
    pref = dict(zip(languages, preference))
    recommend = []
    for lang in table:
        score = 0
        for i, j in enumerate(lang):
            if j in languages:
                score += pref[j] * (6 - i)
        recommend.append([score, lang[0]])
    recommend.sort(key=lambda x: x[1])
    recommend.sort(reverse=True, key=lambda x: x[0])
    return recommend[0][1]
