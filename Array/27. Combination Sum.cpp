// https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    void backtrack(vector<int> &nums, int leftover, vector<vector<int>> &res, vector<int> &v, int idx)
    {
        if (leftover < 0)
            return;
            
        if (leftover == 0)
        {
            res.push_back(v);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            backtrack(nums, leftover - nums[i], res, v, i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;

        backtrack(candidates, target, res, v, 0);
        return res;
    }
};