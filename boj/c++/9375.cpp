#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    string name, kind;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        map<string, int> m;
        int answer = 1;

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> name >> kind;

            if (m.find(kind) != m.end())
                ++m.at(kind);
            else
                m.insert(make_pair(kind, 1));
        }

        for (auto it = m.begin(); it != m.end(); it++)
            answer *= ((*it).second + 1);

        --answer;
        cout << answer << "\n";
    }
    return 0;
}
