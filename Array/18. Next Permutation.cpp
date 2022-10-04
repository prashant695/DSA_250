// https://leetcode.com/problems/next-permutation/

// Method - 1
// Naive approach
// Find all permutations of array
// Time -> O(n!)

// Method - 2
// Time -> O(n)

// [1,2,3]
// [3,2,1]
// [1,1,5]
// [1,3,2]
// [2,3,1,3,3]
// [2,3,1]

// from right to left find index when numbers are not increasing
// for example : [1,4,3,2]
// from backwards increasing numbers are [4,3,2]
// now reverse these numbers
// Now [4,3,2] becomes [2,3,4]
// Now find just greater number of 1
// that is 2
// swap this number
// final answer -> [2,1,3,4]

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;
        for (; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                reverse(nums.begin() + i, nums.end());
                for (int j = i; j < nums.size(); j++)
                    if (nums[j] > nums[i - 1])
                    {
                        swap(nums[j], nums[i - 1]);
                        break;
                    }

                break;
            }
        }
        if (i == 0)
            reverse(nums.begin(), nums.end());
    }
};

// Method - 3
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        int i = nums.size() - 2;
        while (i >= 0 and nums[i] >= nums[i + 1])
            i--;

        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
