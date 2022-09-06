// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> v2;
    void dfs(TreeNode *root, string s)
    {
        if (root)
        {
            if (!root->left && !root->right)
            {
                v2.push_back(s + to_string(root->val));
            }
            dfs(root->left, s + to_string(root->val) + "->");
            dfs(root->right, s + to_string(root->val) + "->");
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return v2;
    }
};