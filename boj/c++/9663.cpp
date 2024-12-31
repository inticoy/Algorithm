#include <iostream>

using namespace std;

int nqueen(int curr, int n, int board[][16])
{
    int answer = 0;
    int attack = 0;

    if (curr > n)
        return 1;

    for (int i = 1; i <= n; i++)
    {
        if (board[0][i])
            continue;

        attack = 0;

        for (int j = 1; j < curr; j++)
        {
            if (board[j][0] == 0)
                continue;

            if (board[j][0] + j == i + curr || board[j][0] - j == i - curr)
                attack = 1;
        }

        if (attack)
            continue;

        board[curr][0] = i;
        board[0][i] = curr;

        answer += nqueen(curr + 1, n, board);

        board[curr][0] = 0;
        board[0][i] = 0;
    };
    board[curr][0] = 0;

    return answer;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n;
    int board[16][16];

    cin >> n;

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            board[i][j] = 0;

    cout << nqueen(1, n, board);
    return 0;
}
