#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int p[301];
    int total[301];

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 0; i <= 300; i++)
        total[i] = -1;

    total[0] = 0;
    total[1] = p[1];
    total[2] = p[1] + p[2];

    for (int i = 3; i <= n; i++)
        total[i] = max(total[i - 3] + p[i - 1] + p[i], total[i - 2] + p[i]);

    cout << total[n];

    return 0;
}
