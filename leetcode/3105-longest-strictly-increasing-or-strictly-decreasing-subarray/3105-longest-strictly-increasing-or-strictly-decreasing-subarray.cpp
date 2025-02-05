class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        vector<int> inc(nums.size(), 1);
        vector<int> dec(nums.size(), 1);

        for (auto i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] < nums[i])
                inc[i] = inc[i-1] + 1;
            else if (nums[i-1] > nums[i])
                dec[i] = dec[i-1] + 1;
        }

        return max(*max_element(inc.begin(), inc.end()), \
                    *max_element(dec.begin(), dec.end()));
    }
};