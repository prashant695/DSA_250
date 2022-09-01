// https://leetcode.com/problems/two-sum/

// Method - 0
// Bruteforce
// Time complexity -> O(n2)

// Method - 1
// Using Auxillary space
// Time complexity -> O(n)
// Space complexity -> O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> nums, int target)
    {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m[target - nums[i]] and i != m[target - nums[i]])
                return {i, m[target - nums[i]]};
        }
    }
    return {};
}

// Method - 1.1
// Using Auxillary space and in one pass
class Solution
{
public:
    vector<int> twoSum(vector<int> nums, int target)
    {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]))
                return {i, m[(target - nums[i])]};
            else
                m[nums[i]] = i;
        }
        return {};
    }
};

// Method - 2
// Sorting and two pointers
// Time complexity -> O(n*logn)
// Space complexity -> O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v = nums, res(2, -1);

        sort(nums.begin(), nums.end());

        int l = 0, h = nums.size() - 1;

        while (l < h)
        {
            if (nums[l] + nums[h] == target)
                break;

            else if (nums[l] + nums[h] < target)
                l++;

            else
                h--;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[l] == v[i] and res[0] == -1)
                res[0] = i;
            else if (nums[h] == v[i] and res[1] == -1)
                res[1] = i;
        }
        return res;
    }
};