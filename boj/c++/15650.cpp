#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNM(string sequence, int n, int m)
{
    string temp;

    if (sequence.size() == m)
    {
        for (int i = 0; i < m - 1; i++)
            cout << sequence.at(i) << " ";
        cout << sequence.at(m - 1) << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        if (sequence.find(i + '0') != string::npos)
            continue;
        if (sequence.size() && upper_bound(sequence.begin(), sequence.end(),
                                           i + '0') != sequence.end())
            continue;
        temp = sequence + to_string(i);
        getNM(temp, n, m);
    };
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m;
    vector<string> vec;

    cin >> n >> m;

    getNM("", n, m);
    return 0;
}