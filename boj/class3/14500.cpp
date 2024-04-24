#include <iostream>
#include <vector>

using namespace std;

int shape[8][2][2] = {{{0, 0}, {0, 1}}, {{0, 0}, {0, 2}}, {{0, 0}, {1, 2}}, {{0, 1}, {0, 2}},
                      {{0, 2}, {1, 0}}, {{1, 0}, {1, 1}}, {{1, 0}, {1, 2}}, {{1, 1}, {1, 2}}};

int getMax(vector<vector<int> > &vec, int n, int m)
{
    int max = -1, temp = 0;

    // 1 * 4
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 3; j++)
        {
            temp = vec.at(i).at(j) + vec.at(i).at(j + 1) + vec.at(i).at(j + 2) + vec.at(i).at(j + 3);
            if (temp > max)
                max = temp;
        }
    }

    // 2 * 2
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            temp = vec.at(i).at(j) + vec.at(i).at(j + 1) + vec.at(i + 1).at(j) + vec.at(i + 1).at(j + 1);
            if (temp > max)
                max = temp;
        }
    }

    // 4 * 1
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp = vec.at(i).at(j) + vec.at(i + 1).at(j) + vec.at(i + 2).at(j) + vec.at(i + 3).at(j);
            if (temp > max)
                max = temp;
        }
    }

    // 2 * 3
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int six = vec.at(i).at(j) + vec.at(i).at(j + 1) + vec.at(i).at(j + 2) + vec.at(i + 1).at(j) +
                          vec.at(i + 1).at(j + 1) + vec.at(i + 1).at(j + 2);
                temp = six - (vec.at(i + shape[k][0][0]).at(j + shape[k][0][1]) +
                              vec.at(i + shape[k][1][0]).at(j + shape[k][1][1]));
                if (temp > max)
                    max = temp;
            }
        }
    }

    // 3 * 2
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int six = vec.at(i).at(j) + vec.at(i).at(j + 1) + vec.at(i + 1).at(j) + vec.at(i + 1).at(j + 1) +
                          vec.at(i + 2).at(j) + vec.at(i + 2).at(j + 1);
                temp = six - (vec.at(i + shape[k][0][1]).at(j + shape[k][0][0]) +
                              vec.at(i + shape[k][1][1]).at(j + shape[k][1][0]));

                if (temp > max)
                    max = temp;
            }
        }
    }

    return max;
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m, value;
    cin >> n >> m;

    vector<vector<int> > vec;
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        temp = vector<int>();
        for (int j = 0; j < m; j++)
        {
            cin >> value;
            temp.push_back(value);
        }
        vec.push_back(temp);
    }

    cout << getMax(vec, n, m);

    return 0;
}