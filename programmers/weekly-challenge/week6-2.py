# 테스트 1 〉	통과 (0.02ms, 10.3MB)
# 테스트 2 〉	통과 (0.03ms, 10.3MB)
# 테스트 3 〉	통과 (0.03ms, 10.3MB)
# 테스트 4 〉	통과 (0.03ms, 10.3MB)
# 테스트 5 〉	통과 (0.03ms, 10.3MB)
# 테스트 6 〉	통과 (125.92ms, 11.1MB)
# 테스트 7 〉	통과 (155.59ms, 11.4MB)
# 테스트 8 〉	통과 (153.51ms, 11.7MB)
# 테스트 9 〉	통과 (44.37ms, 10.6MB)
# 테스트 10 〉	통과 (34.27ms, 10.8MB)
# 테스트 11 〉	통과 (185.75ms, 11.5MB)
# 테스트 12 〉	통과 (140.79ms, 10.9MB)

def solution(weights, head2head):
    num = len(head2head)
    num_boxers = range(num)

    # [win, battle, heavy]
    win_info = [[0, 0, 0] for i in num_boxers]

    for i in num_boxers:
        for j in range(i + 1, num):
            game = head2head[i][j]
            if game == "W":
                win_info[i][0] += 1
                win_info[i][1] += 1
                win_info[j][1] += 1
                if weights[i] < weights[j]:
                    win_info[i][2] += 1
            elif game == "L":
                win_info[i][1] += 1
                win_info[j][0] += 1
                win_info[j][1] += 1
                if weights[i] > weights[j]:
                    win_info[j][2] += 1

    # (win rate, num_heavy, weight, player_num)
    info = [[0, win_info[i][2], weights[i], i + 1] for i in num_boxers]

    for i in num_boxers:
        if win_info[i][1] != 0:
            info[i][0] = win_info[i][0] / win_info[i][1]

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
