#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, m, num;

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        unordered_set<int> note;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> num;
            note.insert(num);
        }

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> num;
            cout << (note.find(num) != note.end() ? "1\n" : "0\n");
        }
    }

    return 0;
}