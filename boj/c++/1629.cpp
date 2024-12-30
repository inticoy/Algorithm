#include <iostream>

using namespace std;

unsigned long long power(unsigned long long a, unsigned long long b, unsigned long long c)
{
    if (b == 1)
        return a % c;

    unsigned long long half = power(a, b / 2, c);
    unsigned long long pow = (half * half) % c;
    if (b % 2)
        pow = (pow * a) % c;

    return pow;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    unsigned long long a, b, c;

    cin >> a >> b >> c;

    cout << power(a, b, c);

    return 0;
}
