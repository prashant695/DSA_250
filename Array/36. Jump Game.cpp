// https://leetcode.com/problems/jump-game/

// Method - 1
// Recursion
// TLE
class Solution
{
public:
    int fun(vector<int> &nums, int j)
    {
        if (j >= nums.size() - 1)
            return 1;

        if (nums[j] == 0)
            return 0;

        for (int i = j + 1; i <= j + nums[j]; i++)
        {
            if (fun(nums, i))
                return 1;
        }

        return 0;
    }

    bool canJump(vector<int> &nums)
    {
        return fun(nums, 0);
    }
};

// Method - 1.1
// Memoization + Recursion
class Solution
{
public:
    int dp[10001];

    int fun(vector<int> &nums, int j)
    {
        if (j >= nums.size() - 1)
            return dp[j] = 1;

        if (nums[j] == 0)
            return dp[j] = 0;

        if (dp[j] != -1)
            return dp[j];

        for (int i = j + 1; i <= j + nums[j]; i++)
        {
            if (fun(nums, i))
                return dp[j] = 1;
        }

        return dp[j] = 0;
    }

    bool canJump(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        return fun(nums, 0);
    }
};

// Method - 3
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (res < i)
                return false;
            res = max(res, i + nums[i]);
        }
        return (res >= nums.size() - 1);
    }
};
