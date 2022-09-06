// https://leetcode.com/problems/recover-binary-search-tree/

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
class Solution
{
public:
    TreeNode *a = NULL, *b = NULL, *prev = NULL;
    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            if (a == NULL && prev != NULL && root->val < prev->val)
                a = prev;
            if (a != NULL && root->val < prev->val)
                b = root;

            prev = root;
            dfs(root->right);
        }
    }
    void recoverTree(TreeNode *root)
    {
        dfs(root);
        swap(a->val, b->val);
    }
};
