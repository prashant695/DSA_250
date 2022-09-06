// https://leetcode.com/problems/unique-binary-search-trees/

// Method - 1
class Solution
{
public:
    long long dp[39][20];
    int numTrees(int n)
    {
        memset(dp, 0, sizeof(dp));
        return ncr(2 * n, n) / (n + 1);
    }
    long long ncr(int n, int r)
    {
        if ((r == 0) || (n == r))
            return 1;

        if (dp[n][r] != 0)
            return dp[n][r];

        return dp[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
};
// Method - 2
class Solution
{
public:
    int numTrees(int n)
    {
        // C0 = 1
        // C1 = 1
        // C2 = C0.C1 + C1.C0
        // C3 = C0.C2 + C1.C1 + C2.C0
        // C4 = C0.C3 + C1.C2 + C2.C1 + C3.C0
        int c[n + 1];
        c[0] = 1;
        c[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int x = 0;
            for (int j = 0; j < i; j++)
            {
                x += (c[j] * c[i - j - 1]);
            }

            c[i] = x;
        }
        return c[n];
    }
};