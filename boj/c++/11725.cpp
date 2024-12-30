#include <iostream>
#include <map>
#include <utility>

using namespace std;

void explore(int n, int node, multimap<int, int> edge, int parent[])
{
    for (multimap<int, int>::iterator it = edge.lower_bound(node); it != edge.upper_bound(node); it++)
    {
        if ((*it).second == parent[node])
            continue;
        parent[(*it).second] = node;
        explore(n, (*it).second, edge, parent);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, a, b;
    int parent[100001];
    multimap<int, int> edge;

    cin >> n;

    for (int i = 0; i <= 100000; i++)
        parent[i] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        edge.insert(make_pair(a, b));
        edge.insert(make_pair(b, a));
    }

    explore(n, 1, edge, parent);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
    return 0;
}