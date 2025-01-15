#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, k;
    vector<long long> v;
    long long answer = 1;

    cin >> s >> k;

    for (int i = 0; i < k; i++)
    {
        if (i < s % k)
            v.push_back(s / k + 1);
        else
            v.push_back(s / k);
    }

    for (auto it = v.begin(); it != v.end(); it++)
        answer *= *it;

    cout << answer;

    return 0;
}