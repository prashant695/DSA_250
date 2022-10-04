// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int s = 0, res = 0;
        unordered_map<int, int> m;
        m[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            if (m.find(s - k) != m.end())
                res += m[s - k];
            m[s]++;
        }
        return res;
    }
};
