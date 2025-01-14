#include <iostream>
#include <string>

using namespace std;

bool validate_ps(string &str)
{
    int stack = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '(')
            ++stack;
        else if (stack <= 0)
            return false;
        else
            --stack;
    }
    return (stack == 0);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    string input;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> input;
        cout << (validate_ps(input) ? "YES\n" : "NO\n");
    }
    return 0;
}
