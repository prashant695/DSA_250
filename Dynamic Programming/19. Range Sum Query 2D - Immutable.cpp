// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
public:
    int pre_sum[201][201] = {{0}};
    NumMatrix(vector<vector<int>> &matrix)
    {
        pre_sum[0][0] = matrix[0][0];

        for (int i = 1; i < matrix.size(); i++)
            pre_sum[i][0] = pre_sum[i - 1][0] + matrix[i][0];

        for (int i = 1; i < matrix[0].size(); i++)
            pre_sum[0][i] = pre_sum[0][i - 1] + matrix[0][i];
            
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] + matrix[i][j] - pre_sum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = pre_sum[row2][col2];

        if (row1 >= 1)
            res -= pre_sum[row1 - 1][col2];

        if (col1 >= 1)
            res -= pre_sum[row2][col1 - 1];

        if (row1 >= 1 && col1 >= 1)
            res += pre_sum[row1 - 1][col1 - 1];

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */