class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max = nums[0];
        int curr = nums[0];

        for (auto i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i])
                curr += nums[i];
            else
                curr = nums[i];

            if (curr > max)
                max = curr;
        }
        
        return max;
    }
};