#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    int a[1000];
    int diff[999];
    int answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
        diff[i] = a[i + 1] - a[i];

    for (int i = 0; i < n - 1; i++)
        if (diff[i] > 0)
            answer++;

    cout << answer + 1;

    return 0;
}
