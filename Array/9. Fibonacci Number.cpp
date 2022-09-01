// https://leetcode.com/problems/fibonacci-number/

// Method - 0
// Recursion
// tc: O(2^n)

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

// Method - 1
// Recursion + Memoization
// tc: O(n)
// sc: O(n)
class Solution
{
public:
    int dp[31] = {0};

    int fib(int n)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        if (dp[n] != 0)
            return dp[n];

        return dp[n] = fib(n - 1) + fib(n - 2);
    }
};

// Method - 2
// Tabulation DP
// tc: O(n)
// sc: O(n)
class Solution
{
public:
    int fib(int n)
    {
        int f[31];
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i < 31; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

// Method - 3
// Space Optimised
// tc: O(n)
// sc: O(1)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        int first = 0, second = 1, tmp;

        for (int i = 2; i <= n; i++)
        {
            tmp = second;
            second = first + second;
            first = tmp;
        }
        return second;
    }
};