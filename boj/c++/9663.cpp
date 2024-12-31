#include <iostream>

using namespace std;

int nqueen(int curr, int n, int row[], int col[])
{
    int answer = 0;
    bool attack = false;

    if (curr > n)
        return 1;

    for (int i = 1; i <= n; i++)
    {
        if (col[i])
            continue;

        attack = false;

        for (int j = 1; j < curr; j++)
            if (row[j] + j == i + curr || row[j] - j == i - curr)
                attack = true;

        if (attack)
            continue;

        row[curr] = i;
        col[i] = curr;

        answer += nqueen(curr + 1, n, row, col);

        row[curr] = 0;
        col[i] = 0;
    };

    return answer;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n;
    int row[15];
    int col[15];

    cin >> n;

    for (int i = 0; i < 15; i++)
    {
        row[i] = 0;
        col[i] = 0;
    }

    cout << nqueen(1, n, row, col);
    return 0;
}
