class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int len1 = word1.size(), len2 = word2.size();
        string answer;

        int m = min(len1, len2);

        for (int i = 0; i < m; i++)
        {
            answer += word1[i];
            answer += word2[i];
        }

        if (len1 > len2)
            answer += string(word1, m);
        else
            answer += string(word2, m);

        return answer;
    }
};