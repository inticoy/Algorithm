#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int dp[101][100001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);

    int n, k, w, v;
    vector<pair<int, int> > item;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        item.push_back(make_pair(w, v));
    }

    for (int i = 1; i <= n; i++)
    {
        int weight = item.at(i - 1).first;
        int value = item.at(i - 1).second;

        for (int j = 1; j <= k; j++)
        {
            if (j - weight < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
        }
    }

    cout << dp[n][k];
    return 0;
}
