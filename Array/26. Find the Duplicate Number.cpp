// https://leetcode.com/problems/find-the-duplicate-number/

// Method - 1
// Map Data Structure

// Method - 2
// Sorting

// Method - 3
// Negative Marking
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i])] *= -1;
        }

        return 0;
    }
};
// Method - 2
// Loop Detection
// https://leetcode.com/problems/find-the-duplicate-number/solution/
class Solution
{
public:
    // Node where the cycle begins
    int findDuplicate(vector<int> &nums)
    {
        int fast = 0, slow = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        slow = 0;
        do
        {
            slow = nums[slow];
            fast = nums[fast];
        } while (fast != slow);

        return fast;
    }
};