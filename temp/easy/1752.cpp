class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;

        for (auto i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1])
                ++count;

        if (nums[nums.size() - 1] > nums[0])
            ++count;

        return count <= 1;
    }
};

/*

class Solution
{
public:
    bool checkIdx(vector<int> &nums, int idx)
    {
        for (auto i = 0; i < idx - 1; i++)
            if (nums[i] > nums[i + 1])
                return false;
        for (auto i = idx; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1])
                return false;
        if (idx != 0 && nums[nums.size() - 1] > nums[0])
            return false;
        return true;
    }

    bool check(vector<int> &nums)
    {
        for (auto i = 0; i < nums.size(); i++)
            if (checkIdx(nums, i))
                return true;
        return false;
    }
};

*/