#include <iostream>

using namespace std;

void infect(int curr, int c, int mat[][100], int virus[])
{
    if (virus[curr] > 0)
        return;

    virus[curr] = 1;
    for (int i = 0; i < c; i++)
        if (mat[curr][i])
            infect(i, c, mat, virus);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, a, b;
    int answer = 0;

    cin >> c;
    cin >> n;

    int mat[100][100];
    int virus[100];

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            mat[i][j] = 0;
        virus[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        mat[a - 1][b - 1] = 1;
        mat[b - 1][a - 1] = 1;
    }

    infect(0, c, mat, virus);

    for (int i = 0; i < c; i++)
        if (virus[i])
            answer++;

    cout << answer - 1;

    return 0;
}
