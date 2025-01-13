#include <iostream>
#include <queue>
#include <set>

using namespace std;

void dfs(int curr, set<int> s[], bool visited[])
{
    if (visited[curr])
        return;
    cout << curr << " ";
    visited[curr] = true;
    for (auto it = s[curr].begin(); it != s[curr].end(); it++)
        dfs(*it, s, visited);
}

void bfs(int curr, set<int> s[], bool visited[])
{
    queue<int> q;
    q.push(curr);

    while (!q.empty())
    {
        if (!visited[q.front()])
        {
            cout << q.front() << " ";
            visited[q.front()] = true;
            for (auto it = s[q.front()].begin(); it != s[q.front()].end(); it++)
                q.push(*it);
        }
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v, a, b;
    set<int> s[1001];
    bool visited[1001];
    bool visited2[1001];

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        s[a].insert(b);
        s[b].insert(a);
    }

    dfs(v, s, visited);
    cout << "\n";
    bfs(v, s, visited2);

    return 0;
}
