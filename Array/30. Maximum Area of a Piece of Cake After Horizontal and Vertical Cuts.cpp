// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &v1, vector<int> &v2)
    {
        long res1 = -1, res2 = -1, mod = 1e9 + 7;
        v1.push_back(0);
        v2.push_back(0);
        v1.push_back(h);
        v2.push_back(w);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 1; i < v1.size(); i++)
            res1 = max(res1, 1l * v1[i] - v1[i - 1]);

        for (int i = 1; i < v2.size(); i++)
            res2 = max(res2, 1l * v2[i] - v2[i - 1]);

        return (res1 % mod * res2 % mod) % mod;
    }
};