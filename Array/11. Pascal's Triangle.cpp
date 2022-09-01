// https://leetcode.com/problems/pascals-triangle/

// Meethod - 1
// Bruteforce (Recursion, nCr)
// tc: O(n! * n2)
class Solution
{
public:
    long long ncr(int n, int r)
    {
        if ((r == 0) || (n == r))
            return 1;

        return ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j <= i; j++)
            {
                v.push_back(ncr(i, j));
            }
            res.push_back(v);
        }
        return res;
    }
};

// Method - 2
// Recursion + Memoization
class Solution
{
public:
    int dp[31][31];
    long long ncr(int n, int r)
    {
        if ((r == 0) || (n == r))
            return 1;

        if (dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
    }
    vector<vector<int>> generate(int n)
    {
        memset(dp, -1, sizeof dp);
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j <= i; j++)
            {
                v.push_back(ncr(i, j));
            }
            res.push_back(v);
        }
        return res;
    }
};

// Method - 3
// tc: O(n2)
// sc: O(n2)
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int n = numRows;

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            vector<int> v(i + 1, 1);
            res.push_back(v);
        }

        for (int i = 2; i < numRows; i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j == 0)
                    continue;

                if (j == res[i].size() - 1)
                    continue;

                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }

        return res;
    }
};