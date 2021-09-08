def solution(weights, head2head):
    num = len(head2head)
    num_boxers = range(num)

    # (win rate, num_heavy, weight, player_num)
    info = [[0, 0, weights[i], i + 1] for i in num_boxers]

    for i in num_boxers:
        total_battle = 0  # number of battle
        total_win = 0  # number of win games
        for j in num_boxers:
            game = head2head[i][j]
            if game == "W":
                total_battle += 1
                total_win += 1
                if weights[i] < weights[j]:
                    info[i][1] += 1
            elif game == "L":
                total_battle += 1
        if total_battle != 0:
            info[i][0] = total_win / total_battle

    answer = []

    for i in num_boxers:
        max_i = 0
        for j in range(1, num - i):
            if info[max_i][0] < info[j][0]:
                max_i = j
            elif info[max_i][0] == info[j][0]:
                if info[max_i][1] < info[j][1]:
                    max_i = j
                elif info[max_i][1] == info[j][1]:
                    if info[max_i][2] < info[j][2]:
                        max_i = j
                    elif info[max_i][2] == info[j][2]:
                        if info[max_i][3] > info[j][3]:
                            max_i = j

        answer.append(info[max_i][3])
        del info[max_i]

    return answer
