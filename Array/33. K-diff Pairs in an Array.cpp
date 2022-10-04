// https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Method - 1
// BruteForce
// tc: O(n2*logn)
// sc: O(n) (set)

// Method - 2
// Two Pointer
// tc: O(nlogn)
// sc: O(1)
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int fast = 1, slow = 0, ans = 0;
        while (slow < nums.size() && fast < nums.size())
        {
            if (nums[fast] - nums[slow] == k)
            {
                ans++;
                fast++;
                slow++;
                while (fast < nums.size() && nums[fast] == nums[fast - 1])
                {
                    fast++;
                }
            }
            else if (nums[fast] - nums[slow] > k)
            {
                slow++;
                if (fast - slow == 0)
                {
                    fast++;
                }
            }
            else
            {
                fast++;
            }
        }
        return ans;
    }
};

// Method - 3
// Map
// tc: O(n)
// sc: O(n)
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        map<int, int> m;
        int cnt = 0;

        for (auto x : nums)
            m[x]++;

        for (auto it : m)
        {
            if (k == 0 and it.second > 1)
                cnt++;

            else if (k >= 1 and m[it.first - k])
                cnt++;
        }
        return cnt;
    }
};
