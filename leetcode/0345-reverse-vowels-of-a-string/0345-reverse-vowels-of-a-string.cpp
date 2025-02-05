class Solution {
public:
    char toLower(char c)
    {
        if ('A' <= c && c <= 'Z')
            return c - 'A' + 'a';
        else
            return c;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        vector<int> vowelIdx;

        for (auto i = 0; i < s.size(); i++)
        {
            if (isVowel(toLower(s[i])))
                vowelIdx.push_back(i);
        }
        
        for (auto i = 0; i < vowelIdx.size() / 2; i++)
        {
            char temp = s[vowelIdx[i]];

            s[vowelIdx[i]] = s[vowelIdx[vowelIdx.size() - i - 1]];
            s[vowelIdx[vowelIdx.size() - i - 1]] = temp;
        }
        
        return s;
    }
};