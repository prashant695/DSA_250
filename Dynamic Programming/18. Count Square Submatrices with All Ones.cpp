// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] && i && j)
                {
                    matrix[i][j] = min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]}) + 1;
                }
                cnt += matrix[i][j];
            }
        }
        return cnt;
    }
};
