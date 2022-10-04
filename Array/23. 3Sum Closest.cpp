// https://leetcode.com/problems/3sum-closest/

// Method 1
// BruteForce
// TC: O(n3)

// Method - 2
// TC: O(n2)
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int x, y, res = 1001;
        for (int i = 0; i < nums.size(); i++)
        {
            x = i + 1;
            y = nums.size() - 1;
            while (x < y)
            {
                if (abs(target - (nums[i] + nums[x] + nums[y])) < abs(res - target))
                    res = (nums[i] + nums[x] + nums[y]);

                if (nums[i] + nums[x] + nums[y] < target)
                    x++;
                else
                    y--;
            }
        }
        return res;
    }
};
