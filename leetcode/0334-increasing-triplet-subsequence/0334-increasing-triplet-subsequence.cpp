class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = nums[0];
        int big = nums[0];
        int temp = nums[0];

        for (auto i = 0; i < nums.size(); i++)
        {
            if (small < big && big < nums[i])
                return true;
            
            if (small < nums[i] && nums[i] < big)
                big = nums[i];
            
            if (temp < nums[i])
            {
                small = temp;
                big = nums[i];
            }

            if (nums[i] < small)
                temp = nums[i];
            
        }
        
        return false;
    }
};