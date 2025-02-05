class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> h;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];

            if (h.find(diff) != h.end())
                return {h[diff], i};
            else
                h.insert({nums[i], i});
        }
        return {};
    }
};