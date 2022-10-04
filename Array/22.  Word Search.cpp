// https://leetcode.com/problems/word-search/

// O(N * (3 ^ L))
// N - Total number of cells in the matrix
// L - word size
// Not 4 ^ L. Why?
// currently we are at a cell i, j.
// Let say we have visited this cell from i - 1, j
// Now, although we make a function call to fun(i - 1, j),
// the function would return false.
// Thus there are 3 function calls that are to proceeded

class Solution
{
public:
    bool fun(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        int r = board.size();
        int c = board[0].size();

        if (k == word.size())
            return 1;

        if (i < 0 or j < 0 or i >= r or j >= c)
            return 0;

        if (board[i][j] != word[k])
            return 0;

        char ch = board[i][j];
        board[i][j] = '@';

        int ans = 0;

        ans = fun(board, word, i + 1, j, k + 1) or
              fun(board, word, i - 1, j, k + 1) or
              fun(board, word, i, j + 1, k + 1) or
              fun(board, word, i, j - 1, k + 1);

        board[i][j] = ch;

        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int r = board.size();
        int c = board[0].size();
        int ans = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans = ans or fun(board, word, i, j, 0);
            }
        }

        return ans;
    }
};