// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Method
// Sliding Window
class Solution
{
public:
    int maxScore(vector<int> &v, int k)
    {
        int win_size = v.size() - k;

        int tot_sum = 0, win_sum = 0;

        for (int i = 0; i < v.size(); i++)
            tot_sum += v[i];

        for (int i = 0; i < win_size; i++)
            win_sum += v[i];

        int res = tot_sum - win_sum;

        for (int i = win_size; i < v.size(); i++)
        {
            win_sum -= v[i - win_size];
            win_sum += v[i];

            res = max(res, tot_sum - win_sum);
        }

        return res;
    }
};
