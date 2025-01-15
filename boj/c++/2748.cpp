#include <iostream>
#include <map>

using namespace std;

long long fib(long long n, map<long long, long long> &m)
{
    if (m.find(n) != m.end())
        return m.at(n);

    long long half = n / 2;

    if (n % 2 == 0)
        m.insert(make_pair(n, (fib(half + 1, m) * fib(half, m) + fib(half, m) * fib(half - 1, m))));
    else
        m.insert(make_pair(n, (fib(half, m) * fib(half, m) + fib(half + 1, m) * fib(half + 1, m))));

    return m.at(n);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    map<long long, long long> m;

    cin >> n;

    m.insert(make_pair(0, 0));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 1));
    m.insert(make_pair(3, 2));

    cout << fib(n, m);

    return 0;
}
