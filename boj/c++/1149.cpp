#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void getMin(vector<vector<int> > &table, int house, int n)
{
    if (house > n)
        return;

    for (int i = 0; i < 3; i++)
    {
        int minCost = 2147483647;
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            if (minCost > table.at(house - 2).at(j))
                minCost = table.at(house - 2).at(j);
        }
        table.at(house - 1).at(i) = table.at(house - 1).at(i) + minCost;
    }
    getMin(table, house + 1, n);
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, cost;
    vector<vector<int> > table;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> costs;
        for (int j = 0; j < 3; j++)
        {
            cin >> cost;
            costs.push_back(cost);
        }
        table.push_back(costs);
    }

    getMin(table, 2, n);

    cout << min(min(table.at(n - 1).at(0), table.at(n - 1).at(1)), table.at(n - 1).at(2));
    return 0;
}