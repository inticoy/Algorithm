#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNM(vector<int> &seq, vector<int> &numbers, int n, int m)
{
    if (seq.size() == static_cast<size_t>(m))
    {
        for (int i = 0; i < m - 1; i++)
            cout << seq.at(i) << " ";
        cout << seq.at(m - 1) << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (find(seq.begin(), seq.end(), numbers.at(i)) != seq.end())
            continue;
        seq.push_back(numbers.at(i));
        getNM(seq, numbers, n, m);
        seq.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m, input;
    vector<int> seq;
    vector<int> numbers;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        numbers.push_back(input);
    }
    sort(numbers.begin(), numbers.end());

    getNM(seq, numbers, n, m);

    return 0;
}