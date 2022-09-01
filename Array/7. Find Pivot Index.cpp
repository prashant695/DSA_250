// https://leetcode.com/problems/find-pivot-index/

// Method - 0
// Bruteforce
// TC: O(n2)

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int leftsum = 0;
            int rightsum = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j < i)
                    leftsum += nums[j];

                else if (j > i)
                    rightsum += nums[j];
            }

            if (leftsum == rightsum)
                return i;
        }

        return -1;
    }
};

// Method - 1
// Using prefix and suffix array
// SC: O(n)

// Method - 1 (space optimised)
// Using prefix array
// SC: O(n)

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int pre[n];

        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        if (pre[0] == pre[n - 1])
            return 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (pre[i - 1] - (pre[n - 1] - pre[i]) == 0)
                return i;
        }
        if (pre[n - 2] == 0)
            return n - 1;
        return -1;
    }
};