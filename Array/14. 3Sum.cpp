// https://leetcode.com/problems/3sum/

// Method 1
// BruteForce
// TC: O(n3)

// Method - 2
// TC: O(n2)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i, j, k, a, target;
        int n = nums.size();

        for (i = 0; i < n; i++)
        {
            j = i + 1;
            k = n - 1;
            target = -nums[i];

            while (j < k)
            {
                int two_sum = nums[j] + nums[k];

                if (two_sum == target)
                {
                    while (j + 1 < n and nums[j] == nums[j + 1])
                        j++;
                    while (k - 1 >= i + 1 and nums[k] == nums[k - 1])
                        k--;
                    res.push_back({nums[i], nums[j], nums[k]}), j++, k--;
                }

                else if (two_sum < target)
                    j++;
                else
                    k--;
            }

            while (i + 1 < n and nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};