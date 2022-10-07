// https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2000, 0));
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int diff = nums[j] - nums[i] + 1000;
                dp[j][diff] = max(2, dp[i][diff] + 1);
                res = max(res, dp[j][diff]);
            }
        }
        return res;
    }
};