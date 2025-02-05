//        1  2  3  4
// front: 1  1  2  6
// back: 24 12  4  1

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> front(len);
        vector<int> back(len);
        vector<int> answer(len);

        front[0] = 1;
        back[len - 1] = 1;

        for (auto i = 1; i < nums.size(); i++)
            front[i] = front[i - 1] * nums[i - 1];
        
        for (auto i = len - 2; i >= 0; i--)
            back[i] = back[i + 1] * nums[i + 1];

        for (auto i = 0; i < nums.size(); i++)
            answer[i] = front[i] * back[i];
        

        return answer;
    }
};