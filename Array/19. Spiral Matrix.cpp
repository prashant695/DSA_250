class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> v;
        int rl = matrix[0].size(), du = matrix.size() - 1;
        int x = 0, y = -1, cnt2 = rl * (du + 1), cnt = 0;

        while (1)
        {
            for (int i = 0; i < rl; i++)
            {
                v.push_back(matrix[x][++y]);
                cnt++;
                if (cnt == cnt2)
                {
                    return v;
                }
            }
            rl--;

            for (int i = 0; i < du; i++)
            {
                v.push_back(matrix[++x][y]);
                cnt++;
                if (cnt == cnt2)
                {
                    return v;
                }
            }
            du--;
            for (int i = 0; i < rl; i++)
            {
                v.push_back(matrix[x][--y]);
                cnt++;
                if (cnt == cnt2)
                {
                    return v;
                }
            }
            rl--;
            for (int i = 0; i < du; i++)
            {
                v.push_back(matrix[--x][y]);
                cnt++;
                if (cnt == cnt2)
                {
                    return v;
                }
            }
            du--;

            if (rl <= 0 && du <= 0)
            {
                return v;
            }
        }
        return v;
    }
};