// https://leetcode.com/problems/running-sum-of-1d-array/

// Method - 0
// Bruteforce
// Time complexity -> O(n2)

// Method - 1
// SC: O(n)
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> res(nums.size());

        res[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
            res[i] = res[i - 1] + nums[i];

        return res;
    }
};

// Method - 2
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];

        return nums;
    }
};