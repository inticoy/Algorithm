#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, number;
    vector<vector<int> > vec;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        for (int j = 0; j <= i; j++)
        {
            cin >> number;
            line.push_back(number);
        }
        vec.push_back(line);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            vec.at(i).at(j) =
                vec.at(i).at(j) +
                (vec.at(i + 1).at(j) > vec.at(i + 1).at(j + 1) ? vec.at(i + 1).at(j) : vec.at(i + 1).at(j + 1));
        }
    }

    cout << vec.at(0).at(0);

    return 0;
}
