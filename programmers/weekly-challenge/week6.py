import operator


def solution(weights, head2head):
    num_boxers = range(len(head2head))
    win_rate = [0. for i in num_boxers]  # win rate for each boxers
    # number of win heavier boxers for each boxers
    num_heavy = [0 for i in num_boxers]
    answer = []

    for i in num_boxers:
        total_battle = 0  # number of battle
        total_win = 0  # number of win games
        for j in num_boxers:
            game = head2head[i][j]
            if game == "W":
                total_battle += 1
                total_win += 1
                if weights[i] < weights[j]:
                    num_heavy[i] += 1
            elif game == "L":
                total_battle += 1
        if total_battle != 0:
            win_rate[i] = total_win / total_battle

    values = [10000000000 * win_rate[i] * 100 +
              10000000 * num_heavy[i] +
              10000 * weights[i] +
              len(weights) - i for i in num_boxers]

    test = dict(zip(range(1, len(weights) + 1), values))
    stest = sorted(test.items(), key=operator.itemgetter(1), reverse=True)
    answer = [i[0] for i in stest]
    return answer
