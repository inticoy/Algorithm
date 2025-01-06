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
        table.insert(make_pair(make_pair(y, x), 0));
    }

    for (auto it = table.begin(); it != table.end(); it++)
        cout << (*it).first.second << " " << (*it).first.first << "\n";

    return 0;
}
