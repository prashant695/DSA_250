// https://leetcode.com/problems/palindromic-substrings/

// Method - 1 (Generate All substrings (O(n2)) and checking for the palindrome (O(n)) )
// BruteForce
// tc: O(n3)

class Solution
{
public:
    int palindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return 0;
        }
        return 1;
    }
    int countSubstrings(string s)
    {
        string temp;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            temp = s[i];
            for (int j = i + 1; j < s.size(); j++)
            {
                temp += s[j];
                res += palindrome(temp);
            }
        }
        return res + s.size();
    }
};

// Method - 2
// Optimised Version (Generate All substrings (O(n2)) and checking for the palindrome (O(1)) )
// tc: O(n2)
class Solution
{
public:
    int dp[1000][1000];
    int palindrome(string s, int i, int j)
    {
        if (s.size() == 2)
        {
            if (s[0] == s[1])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
        int x = s[0];
        int y = s[s.size() - 1];

        if (x == y && dp[i + 1][j - 1])
            dp[i][j] = 1;
        else
            dp[i][j] = 0;

        return dp[i][j];
    }
    int countSubstrings(string s)
    {
        memset(dp, -1, sizeof(dp));
        string temp;
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            temp = s[i];
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                temp += s[j];
                res += palindrome(temp, i, j);
            }
        }
        return res + s.size();
    }
};