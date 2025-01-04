#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k, a, b, c;
    map<int, int> m[20001];
    multimap<int, pair<int, int> > w;
    bool visited[20001] = {false};
    int min[20001];

    cin >> v >> e >> k;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        if (m[a].find(b) == m[a].end())
            m[a].insert(make_pair(b, c));
        else if (m[a].at(b) > c)
            m[a].at(b) = c;
        else
            continue;
    }

    fill(min, min + 20001, 1000000000);
    min[k] = 0;

    w.insert(make_pair(0, make_pair(k, k)));

    while (!w.empty())
    {
        auto info = *w.begin();
        int value = info.first;
        int dep = info.second.first;
        int dest = info.second.second;

        w.erase(w.begin());

        if (visited[dest])
            continue;

        visited[dest] = true;

        for (auto it = m[dest].begin(); it != m[dest].end(); it++)
        {
            if (min[(*it).first] > min[dest] + (*it).second)
            {
                min[(*it).first] = min[dest] + (*it).second;
                w.insert(make_pair(min[(*it).first], make_pair(dest, (*it).first)));
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (min[i] == 1000000000)
            cout << "INF\n";
        else
            cout << min[i] << "\n";
    }

    return 0;
}
