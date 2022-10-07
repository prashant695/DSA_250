// https://leetcode.com/problems/unique-paths/

// Method - 1
// Recursion + Memoization
class Solution
{
public:
    int dp[100][100];
    int fun(int x, int y)
    {
        if (x == 0 and y == 0)
            return 1;

        if (x < 0 or y < 0)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        int w1 = fun(x - 1, y);
        int w2 = fun(x, y - 1);

        return dp[x][y] = w1 + w2;
    }
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof dp);
        return fun(m - 1, n - 1);
    }
};

// Method - 2
// Tabulation DP
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        int dp[100][100];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int w1 = 0, w2 = 0;
                    w1 = dp[i - 1][j];
                    w2 = dp[i][j - 1];
                    dp[i][j] = w1 + w2;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Method - 2
// Tabulation DP (Space Optimised)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)
                {
                    cur[j] = 1;
                }
                else
                {
                    int w1 = 0, w2 = 0;
                    w1 = prev[j];
                    w2 = cur[j - 1];
                    cur[j] = w1 + w2;
                }
            }

            prev = cur;
        }
        return prev[n - 1];
    }
};
