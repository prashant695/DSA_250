// https://leetcode.com/problems/delete-and-earn/

// Method - 1
// Tabulation DP
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> v(20000, 0), dp(20000);
        for (auto x : nums)
            v[x] += x;

        dp[0] = v[0];
        dp[1] = v[1];

        for (int i = 2; i < 20000; i++)
            dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);

        return max(dp[19999], dp[19998]);
    }
};
