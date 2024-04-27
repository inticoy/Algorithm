#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int atob(long long a, long long b)
{
    queue<pair<long long, int> > Q;
    Q.push(make_pair(a, 1));

    while (!Q.empty())
    {
        long long number = Q.front().first;
        int step = Q.front().second;

        if (number == b)
            return step;

        if (number * 2 <= b)
            Q.push(make_pair(number * 2, step + 1));
        if (number * 10 + 1 <= b)
            Q.push(make_pair(number * 10 + 1, step + 1));

        Q.pop();
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int a, b;

    cin >> a >> b;

    cout << atob(a, b) + 0;
    return 0;
}
