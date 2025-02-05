class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 == str2)
            return str1;

        if (str1.size() < str2.size())
        {
            string temp = str2;
            str2 = str1;
            str1 = temp;
        }

        if (string(str1, 0, str2.size()) == str2)
            return gcdOfStrings(string(str1, str2.size()), str2);

        return "";
    }
};