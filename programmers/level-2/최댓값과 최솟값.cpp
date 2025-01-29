#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int min = 2147483647, max = -2147483648;
    stringstream ss;

    while (s.length() != 0)
    {
        int curr = stoi(s);

        if (min > curr)
            min = curr;
        if (max < curr)
            max = curr;

        int space = 0;
        for (space = 0; space < s.length(); space++)
            if (s.at(space) == ' ')
                break;

        if (space == s.length())
            break;

        s = string(s, space + 1);
    }
    ss << min << " " << max;
    answer = ss.str();
    return answer;
}