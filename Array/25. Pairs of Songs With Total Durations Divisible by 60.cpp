// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int m[60] = {0}, cnt = 0;
        for (int i = 0; i < time.size(); i++)
        {
            if (time[i] % 60 == 0)
                cnt += m[0];
            else
                cnt += m[60 - time[i] % 60];
            m[time[i] % 60]++;
        }
        return cnt;
    }
};