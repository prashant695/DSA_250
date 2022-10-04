// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Method - 1
// Map data structure
// tc: O(nlogn)
// sc: O(n)

// Method - 2
// tc: O(n)
// sc: O(1)
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            int pos = abs(nums[i]);
            if (nums[pos - 1] < 0)
            {
                v.push_back(pos);
            }
            else
            {
                nums[pos - 1] *= -1;
            }
        }

        return v;
    }
};
