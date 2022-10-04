// https://leetcode.com/problems/container-with-most-water/

// Method 1
// BruteForce
// TC: O(n2)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxx = -1;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                if (min(height[i], height[j]) * (j - i) > maxx)
                    maxx = (min(height[i], height[j]) * (j - i));
            }
        }
        return maxx;
    }
};

// Method - 2
// TC: O(n)
// https://leetcode.com/problems/container-with-most-water/discuss/200246/Proof-by-formula
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = -1, temp = -1;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            area = abs(i - j) * min(height[i], height[j]);
            temp = max(temp, area);

            if (height[i] < height[j])
                i += 1;
            else
                j -= 1;
        }
        return temp;
    }
};