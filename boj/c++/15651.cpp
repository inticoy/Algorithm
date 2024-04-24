#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNM(string sequence, int n, int m)
{
    string temp = "";

    if (sequence.size() == m)
    {
        for (int i = 0; i < m - 1; i++)
            cout << sequence.at(i) << " ";
        cout << sequence.at(m - 1) << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        temp = sequence + to_string(i);
        getNM(temp, n, m);
    }
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