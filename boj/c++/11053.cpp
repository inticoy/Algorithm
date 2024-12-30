#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    int a[1000];
    int dp[1000];
    int answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
    }

    for (int i = 0; i < n; i++)
        if (dp[i] > answer)
            answer = dp[i];

    cout << answer;

    return 0;
}
