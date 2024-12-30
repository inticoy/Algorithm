#include <algorithm>
#include <iostream>

using namespace std;

int mat[1025][1025];
int sum[1025][1025];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m, x1, x2, y1, y2;

    fill(&mat[0][0], &mat[0][0] + sizeof(mat) / sizeof(int), 0);
    fill(&sum[0][0], &sum[0][0] + sizeof(sum) / sizeof(int), 0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = mat[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];

    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}
