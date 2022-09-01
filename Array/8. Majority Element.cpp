// https://leetcode.com/problems/majority-element/

// Method - 0
// Bruteforce
// Time complexity -> O(n2)

// Method - 1
// Using Map
// tc: O(n)
// sc: o(n)

// Method - 2
// Sorting
// tc: O(n logn)
// sc: o(1)

// Method - 3
// Boyer-Moore Voting Algorithm
// t.c-> O(n)   s.c-> O(1)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candid = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
                candid = nums[i];

            if (nums[i] == candid)
                cnt++;
            else
                cnt--;
        }
        return candid;
    }
};
