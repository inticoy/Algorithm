#include <iostream>
#include <map>

using namespace std;

long long fib(long long n, map<long long, int> &m)
{
    if (m.find(n) != m.end())
        return m.at(n);

    long long half = n / 2;

    if (n % 2 == 0)
        m.insert(make_pair(n, (fib(half + 1, m) * fib(half, m) + fib(half, m) * fib(half - 1, m)) % 1000000007));
    else
        m.insert(make_pair(n, (fib(half, m) * fib(half, m) + fib(half + 1, m) * fib(half + 1, m)) % 1000000007));

    return m.at(n);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    map<long long, int> m;

    cin >> n;

    m.insert(make_pair(0, 0));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 1));
    m.insert(make_pair(3, 2));

    cout << fib(n, m);

    return 0;
}

// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610

// 2(3)0 1 1 0 1 1 0 1 1 0

// 3(8)0 1 1 2 0 2 2 1 0 1 1

// 4(6)0 1 1 2 3 1 0 1 1 2 3 1

// 5(20)0 1 1 2 3 0 3 3 1 4 0 4 4 3 2 0 2 2 4 1 0 1 1 2 3 0