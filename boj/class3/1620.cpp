#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isInt(string &input)
{
    for (int i = 0; i < input.size(); i++)
        if ('0' > input.at(i) || input.at(i) > '9')
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m, id = 1;
    string name, input;
    map<int, string> intMap;
    map<string, int> strMap;

    cin >> n >> m;

    for (int i = 0; i < n; i++, id++)
    {
        cin >> name;
        intMap.insert(make_pair(id, name));
        strMap.insert(make_pair(name, id));
    }

    for (int i = 0; i < m; i++)
    {
        cin >> input;
        if (isInt(input))
            cout << (*intMap.find(stoi(input))).second << "\n";
        else
            cout << (*strMap.find(input)).second << "\n";
    }
    return 0;
}