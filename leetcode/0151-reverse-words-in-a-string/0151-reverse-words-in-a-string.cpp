class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        string temp;
        stringstream ss(s);
        stringstream out;

        while (ss >> temp)
            words.push_back(temp);

        for (auto i = 0; i < words.size(); i++)
        {
            out << words[words.size() - i - 1];
            if (i != words.size() - 1)
                out << " ";
        }

        return out.str();        
    }
};