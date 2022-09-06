// https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root)
        {
            if (root->left and root->left->left == NULL and root->left->right == NULL)
                return root->left->val + sumOfLeftLeaves(root->right);

            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
        return 0;
    }
};