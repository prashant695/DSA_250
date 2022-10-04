// https://leetcode.com/problems/subsets/

// Method - 1
// Bits Manipulation
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> sub;
        int num;
        for (int i = 0; i < pow(2, nums.size()); i++)
        {
            sub.clear();
            for (int j = 0; j < nums.size(); j++)
            {
                num = 1 << j;
                if (num & i)
                    sub.push_back(nums[j]);
            }
            res.push_back(sub);
        }
        return res;
    }
};

// Method - 2
// BackTracking
class Solution
{
public:
    void fun(vector<int> &nums, int i, vector<vector<int>> &res, vector<int> path)
    {
        if (i == nums.size())
        {
            res.push_back(path);
            return;
        }

        fun(nums, i + 1, res, path);
        path.push_back(nums[i]);
        fun(nums, i + 1, res, path);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        fun(nums, 0, res, path);
        return res;
    }
};

