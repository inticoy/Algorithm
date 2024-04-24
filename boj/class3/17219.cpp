#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n, m;
    string site, pwd;
    map<string, string> data;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> site >> pwd;
        data.insert(make_pair(site, pwd));
    }

    for (int i = 0; i < m; i++)
    {
        cin >> site;
        cout << (*data.find(site)).second << "\n";
    }

    return 0;
}