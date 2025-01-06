#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    multimap<pair<int, int>, int> table;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        table.insert(make_pair(make_pair(x, y), 0));
    }

    for (auto it = table.begin(); it != table.end(); it++)
        cout << (*it).first.first << " " << (*it).first.second << "\n";

    return 0;
}
