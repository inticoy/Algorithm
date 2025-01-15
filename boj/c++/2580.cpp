#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool sudoku(int x, int y, vector<vector<int>> &v, set<int> row[], set<int> col[], set<int> sec[])
{
    if (x == 9)
        return sudoku(0, y + 1, v, row, col, sec);
    if (y == 9)
        return true;

    if (v.at(y).at(x) != 0)
        return sudoku(x + 1, y, v, row, col, sec);
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[y].find(i) != row[y].end())
                continue;
            if (col[x].find(i) != col[x].end())
                continue;
            if (sec[(y / 3) * 3 + x / 3].find(i) != sec[(y / 3) * 3 + x / 3].end())
                continue;

            v.at(y).at(x) = i;
            row[y].insert(i);
            col[x].insert(i);
            sec[(y / 3) * 3 + x / 3].insert(i);
            bool result = sudoku(x + 1, y, v, row, col, sec);
            if (result)
                return result;
            else
            {
                v.at(y).at(x) = 0;
                row[y].erase(i);
                col[x].erase(i);
                sec[(y / 3) * 3 + x / 3].erase(i);
                continue;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v(9);
    set<int> row[9];
    set<int> col[9];
    set<int> sec[9];

    int n;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> n;
            v.at(i).push_back(n);

            if (n != 0)
            {
                row[i].insert(n);
                col[j].insert(n);
                sec[(i / 3) * 3 + j / 3].insert(n);
            }
        }
    }

    sudoku(0, 0, v, row, col, sec);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << v.at(i).at(j) << " ";
        }
        cout << "\n";
    }

    return 0;
}
