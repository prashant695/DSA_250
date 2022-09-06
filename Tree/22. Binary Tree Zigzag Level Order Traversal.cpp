// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Method - 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Method - 1
// Using Reverse operation
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int flg = 1;
        vector<vector<int>> res;
        queue<TreeNode *> q;

        if (!root)
            return res;

        q.push(root);

        while (!q.empty())
        {
            flg = !flg;
            int qu = q.size();
            vector<int> v;

            for (int i = 0; i < qu; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                v.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            if (flg)
                reverse(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }
};

// Method - 2
// Without Using Reverse operation
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int flg = 1;
        vector<vector<int>> res;
        queue<TreeNode *> q;

        if (!root)
            return res;

        q.push(root);

        while (!q.empty())
        {
            flg = !flg;
            int qu = q.size();
            vector<int> v(qu);

            for (int i = 0; i < qu; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (flg)
                    v[qu - i - 1] = curr->val;
                else
                    v[i] = curr->val;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            res.push_back(v);
        }
        return res;
    }
};