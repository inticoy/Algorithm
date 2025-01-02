#include <algorithm>
#include <iostream>
#include <string>

// AACGGAACACGCTTTAAGGGCGATGGAATACCGTGGGTTTACCTAAAACTA
// AATCTGGCCTATTCTGGGTCAAATGGCGTGAGCAAACATCGTACA

using namespace std;

static int dp[1001][1001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;

    cin >> a >> b;

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a.at(i - 1) == b.at(j - 1))
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[a.size()][b.size()];

    return 0;
}
