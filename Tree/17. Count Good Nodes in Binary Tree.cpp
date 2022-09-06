// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    void dfs(TreeNode *root, int maxx, int &cnt)
    {
        if (!root)
            return;

        if (root->val >= maxx)
            cnt++;

        dfs(root->left, max(maxx, root->val), cnt);
        dfs(root->right, max(maxx, root->val), cnt);
    }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        dfs(root, root->val, cnt);
        return cnt;
    }
};