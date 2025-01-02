#include <iostream>
#include <utility>
#include <vector>

using namespace std;

static int original[10][10];
static int arr[10][10];

void copy(int n, int m, int original[][10], int arr[][10])
{
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            arr[i][j] = original[i][j];
}

void spread(int xo, int yo, int x, int y, int arr[][10])
{
    if (arr[x - 1][y] == 0 && x - 1 != xo)
    {
        arr[x - 1][y] = 2;
        spread(x, y, x - 1, y, arr);
    }
    if (arr[x][y - 1] == 0 && y - 1 != yo)
    {
        arr[x][y - 1] = 2;
        spread(x, y, x, y - 1, arr);
    }
    if (arr[x + 1][y] == 0 && x + 1 != xo)
    {
        arr[x + 1][y] = 2;
        spread(x, y, x + 1, y, arr);
    }
    if (arr[x][y + 1] == 0 && y + 1 != yo)
    {
        arr[x][y + 1] = 2;
        spread(x, y, x, y + 1, arr);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    int answer = 0;
    int safe = 0;

    vector<pair<int, int> > v0;
    vector<pair<int, int> > v2;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x == 0)
                v0.push_back(make_pair(i + 1, j + 1));
            else if (x == 2)
                v2.push_back(make_pair(i + 1, j + 1));
            original[i + 1][j + 1] = x;
        }
    }

    for (int i = 0; i <= n + 1; i++)
    {
        if (i == 0 || i == n + 1)
            for (int j = 0; j <= m + 1; j++)
                original[i][j] = 1;
        else
            original[i][0] = original[i][m + 1] = 1;
    }

    for (auto it1 = v0.begin(); it1 != v0.end(); it1++)
    {
        for (auto it2 = it1 + 1; it2 != v0.end(); it2++)
        {
            for (auto it3 = it2 + 1; it3 != v0.end(); it3++)
            {
                safe = 0;

                pair<int, int> a = *it1;
                pair<int, int> b = *it2;
                pair<int, int> c = *it3;

                copy(n, m, original, arr);

                arr[a.first][a.second] = 1;
                arr[b.first][b.second] = 1;
                arr[c.first][c.second] = 1;

                for (auto it = v2.begin(); it != v2.end(); it++)
                    spread(0, 0, (*it).first, (*it).second, arr);

                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        if (arr[i][j] == 0)
                            safe++;

                if (safe > answer)
                    answer = safe;
            }
        }
    }

    cout << answer;

    return 0;
}
