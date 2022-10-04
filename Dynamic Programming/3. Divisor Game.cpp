// https://leetcode.com/problems/divisor-game/

// Method - 1
// BruteForce (Recursion)
class Solution
{
public:
    bool help(int n)
    {
        if (n == 1)
            return 0;

        for (int i = 1; i < n; i++)
        {
            if (n % i == 0 && help(n - i) == 0)
                return 1;
        }
        return 0;
    }
    bool divisorGame(int n)
    {
        return help(n);
    }
};

// Method - 2
// Recursion + Memoization
class Solution
{
public:
    int dp[1001];
    bool help(int n)
    {
        if (dp[n] != -1)
            return dp[n];

        if (n == 1)
            return dp[1] = 0;

        for (int i = 1; i < n; i++)
        {
            if (n % i == 0 && help(n - i) == 0)
                return dp[n] = 1;
        }
        return dp[n] = 0;
    }
    bool divisorGame(int n)
    {
        memset(dp, -1, sizeof(dp));
        return help(n);
    }
};

// Method - 3

// If N is even, can win.
// If N is odd, will lose.

// Recursive Prove （Top-down)
// If N is even.
// We can choose x = 1.
// The opponent will get N - 1, which is a odd.
// Reduce to the case odd and he will lose.

// If N is odd,
// 2.1 If N = 1, lose directly.
// 2.2 We have to choose an odd x.
// The opponent will get N - x, which is a even.
// Reduce to the case even and he will win.

// So the N will change odd and even alternatively until N = 1.

class Solution
{
public:
    bool divisorGame(int n)
    {
        return n % 2 == 0;
    }
};
