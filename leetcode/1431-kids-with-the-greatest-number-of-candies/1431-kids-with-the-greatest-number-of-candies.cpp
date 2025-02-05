class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> b;
        int M = *max_element(candies.begin(), candies.end());

        for (const int &x: candies)
            b.push_back(x + extraCandies >= M);

        return b;
    }
};