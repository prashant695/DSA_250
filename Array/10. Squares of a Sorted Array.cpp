// https://leetcode.com/problems/squares-of-a-sorted-array/

// Method - 1
// Bruteforce
// tc: O(n logn)
// sc: O(n)

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &v)
    {
        vector<int> v2;
        for (int i = 0; i < v.size(); i++)
        {
            v2.push_back(v[i] * v[i]);
        }
        sort(v2.begin(), v2.end());
        return v2;
    }
};

// Method - 1
// sorting
// tc: O(n logn)
// sc: O(1)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = nums[i] * nums[i];

        sort(nums.begin(), nums.end());

        return nums;
    }
};

// Method - 2
// tc: O(n)
// sc: O(n)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        vector<int> res(nums.size());
        int k = nums.size() - 1;

        while (i <= j)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
                res[k--] = nums[i] * nums[i], i++;
            else
                res[k--] = nums[j] * nums[j], j--;
        }

        return res;
    }
};
