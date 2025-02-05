class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('\0');
        
        int idx = 0;
        int num = 1;

        for (auto i = 1; i < chars.size(); i++)
        {
            if (chars[i-1] == chars[i])
                ++num;
            else
            {
                chars[idx++] = chars[i-1];
                if (num > 1)
                {
                    for (char c : to_string(num))
                        chars[idx++] = c;
                }
                num = 1;
            }
        }

        return idx;
    }
};