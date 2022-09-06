// https://leetcode.com/problems/range-sum-of-bst/

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
// Bruteforce
class Solution
{
public:
    int sum = 0;
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root != NULL)
        {
            rangeSumBST(root->left, low, high);
            if (root->val >= low && root->val <= high)
                sum += root->val;
            rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};

// Method - 2
// Using BST Property

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;

        else if (root->val < low)
            return rangeSumBST(root->right, low, high);

        else if (root->val > high)
            return rangeSumBST(root->left, low, high);

        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};