// https://leetcode.com/problems/move-zeroes/

// Method - 1
// Using Auxillary array
// TC: O(n)
// SC: O(n)

// Method - 2
// TC: O(n)
// SC: O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                nums[k++] = nums[i];
        }
        for (int i = k; i < nums.size(); i++)
        {
            nums[k++] = 0;
        }
    }
};

// Method - 3
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                swap(nums[k++], nums[i]);
        }
    }
};