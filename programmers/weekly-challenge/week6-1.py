# 테스트 1 〉	통과 (0.02ms, 10.3MB)
# 테스트 2 〉	통과 (0.02ms, 10.1MB)
# 테스트 3 〉	통과 (0.03ms, 10.1MB)
# 테스트 4 〉	통과 (0.02ms, 10.3MB)
# 테스트 5 〉	통과 (0.02ms, 10.2MB)
# 테스트 6 〉	통과 (88.02ms, 10.8MB)
# 테스트 7 〉	통과 (123.32ms, 11.5MB)
# 테스트 8 〉	통과 (125.75ms, 11.5MB)
# 테스트 9 〉	통과 (39.05ms, 10.6MB)
# 테스트 10 〉	통과 (34.97ms, 10.4MB)
# 테스트 11 〉	통과 (134.12ms, 11.3MB)
# 테스트 12 〉	통과 (112.71ms, 10.9MB)

def solution(weights, head2head):
    num = len(head2head)
    num_boxers = range(num)
    win_rate = [0 for i in num_boxers]  # win rate for each boxers
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
        max_i = 0
        for j in range(1, num - i):
            if win_rate[max_i] < win_rate[j]:
                max_i = j
            elif win_rate[max_i] == win_rate[j]:
                if num_heavy[max_i] < num_heavy[j]:
                    max_i = j
                elif num_heavy[max_i] == num_heavy[j]:
                    if weights[max_i] < weights[j]:
                        max_i = j
                    elif weights[max_i] == weights[j]:
                        if player_num[max_i] > player_num[j]:
                            max_i = j

        answer.append(player_num[max_i] + 1)
        del win_rate[max_i]
        del num_heavy[max_i]
        del weights[max_i]
        del player_num[max_i]

    return answer
