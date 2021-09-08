import operator


def solution(weights, head2head):
    num = len(head2head)
    num_boxers = range(num)
    win_rate = [0. for i in num_boxers]  # win rate for each boxers
    # number of win heavier boxers for each boxers
    num_heavy = [0 for i in num_boxers]

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

    answer = []
    player_num = [i for i in num_boxers]

    for i in num_boxers:
        max_index = i
        for j in range(i + 1, num):
            if win_rate[max_index] < win_rate[j]:
                max_index = j
            elif win_rate[max_index] == win_rate[j]:
                if num_heavy[max_index] < win_rate[j]:
                    max_index = j
                elif num_heavy[max_index] == win_rate[j]:
                    if weights[max_index] < weights[j]:
                        max_index = j
                    elif weights[max_index] == weights[j]:
                        if player_num[max_index] > player_num[j]:
                            max_index = j
        win_rate[i], win_rate[max_index] = win_rate[max_index], win_rate[i]
        num_heavy[i], num_heavy[max_index] = num_heavy[max_index], num_heavy[i]
        weights[i], weights[max_index] = weights[max_index], weights[i]
        player_num[i], player_num[max_index] = player_num[max_index], player_num[i]

    player_num = [(i + 1) for i in player_num]

    return player_num
