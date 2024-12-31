#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int t, n, answer;
    int sticker[2][100000];
    int dp[2][100000];

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> sticker[0][j];
        for (int j = 0; j < n; j++)
            cin >> sticker[1][j];

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];

        if (n > 1)
        {
            dp[0][1] = sticker[1][0] + sticker[0][1];
            dp[1][1] = sticker[0][0] + sticker[1][1];
        }

        for (int j = 2; j < n; j++)
        {
            dp[0][j] = sticker[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] = sticker[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    return 0;
}
