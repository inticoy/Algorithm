#include <iostream>
#include <vector>

using namespace std;

void explore(int n, int node, vector<int> edge[], int parent[])
{
    for (vector<int>::iterator it = edge[node].begin(); it != edge[node].end(); it++)
    {
        if ((*it) == parent[node])
            continue;
        parent[(*it)] = node;
        explore(n, (*it), edge, parent);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, a, b;
    int parent[100001] = {0};
    vector<int> edge[100001];

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    explore(n, 1, edge, parent);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
    return 0;
}