// https://leetcode.com/problems/knight-dialer/

class Solution
{
public:
    vector<vector<int>> v = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    int mod = 1000000007;
    int dp[11][5001];
    int dfs(int i, int len, int n)
    {
        if (len == n)
        {
            dp[i][len] = 1;
            return 1;
        }
        int c = 0;
        if (dp[i][len] != -1)
            return dp[i][len];
        for (int j = 0; j < v[i].size(); j++)
        {
            c = (c % mod + dfs(v[i][j], len + 1, n) % mod) % mod;
        }
        return dp[i][len] = c;
    }
    int knightDialer(int n)
    {
        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            cnt = (cnt % mod + dfs(i, 1, n) % mod) % mod;
        }
        return cnt;
    }
};
