#include <iostream>

using namespace std;

int maxRoute(int N, int *p, int currLv)
{
    if (currLv == 0)
        return 0;
    else if (currLv < 0)
        return -1;
    else if (currLv == 1)
        return p[currLv];
    else if (currLv == 2)
        return p[currLv] + p[currLv - 1];

    int two = maxRoute(N, p, currLv - 2);
    int three = maxRoute(N, p, currLv - 3);

    if (three < 0 || two > three + p[currLv - 1])
    {
        return two + p[currLv];
    }
    else
    {
        return three + p[currLv - 1] + p[currLv];
    }
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int P[301];

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i];

    cout << maxRoute(N, P, N);

    return 0;
}
