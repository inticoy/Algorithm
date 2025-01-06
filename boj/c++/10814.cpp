#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, age;
    string name;
    multimap<int, string> members;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        members.insert(make_pair(age, name));
    }

    for (auto it = members.begin(); it != members.end(); it++)
        cout << (*it).first << " " << (*it).second << "\n";
    return 0;
}
