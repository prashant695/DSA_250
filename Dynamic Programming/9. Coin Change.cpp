// https://leetcode.com/problems/coin-change/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n * amt)
// Space Complexity : O(n * amt)

class Solution
{
public:
    int dp[10001][13];
    int fun(vector<int> &coins, int amount, int i)
    {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX - 1;

        if (i < 0 or i >= coins.size())
            return INT_MAX - 1;

        if (dp[amount][i] != -1)
            return dp[amount][i];

        int val1 = 1 + fun(coins, amount - coins[i], i + 1);
        // Take the coin and move ahead    --- eq1

        int val2 = fun(coins, amount, i + 1);
        // Do not take the coin and move ahead    --- eq2

        int val3 = 1 + fun(coins, amount - coins[i], i);
        // Take the coin and stay on same position    --- eq3

        // the equation 1 can be handled through eq2 and eq3
        // AS
        // Take the coin and stay on same position
        // And then Do not take the coin and move ahead
        // Is equivalent to
        // Take the coin and move ahead
        // Thus equation 1 can be deleted from the 3 conditions

        return dp[amount][i] = min({val1, val2, val3});
    }
    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof dp);
        int val = fun(coins, amount, 0);

        if (val == INT_MAX - 1)
            return -1;
        return val;
    }
};

// Method - 2
// Tabulation DP
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[coins.size() + 1][amount + 1];

        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 0;

        for (int i = 0; i <= amount; i++)
            dp[0][i] = 100000;

        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        if (dp[coins.size()][amount] >= 10000)
            return -1;
            
        return dp[coins.size()][amount];
    }
};
