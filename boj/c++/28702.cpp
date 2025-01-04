#include <iostream>
#include <string>

using namespace std;

string fizzbuzz(int i)
{
    if (i % 15 == 0)
        return "FizzBuzz";
    else if (i % 5 == 0)
        return "Buzz";
    else if (i % 3 == 0)
        return "Fizz";
    else
        return to_string(i);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int num;

    for (int i = 0; i < 3; i++)
    {
        cin >> str;
        num = (str == "Fizz" || str == "Buzz" || str == "FizzBuzz") ? 0 : stoi(str);
        if (num)
        {
            cout << fizzbuzz(num + (3 - i));
            break;
        }
    }
    return 0;
}
