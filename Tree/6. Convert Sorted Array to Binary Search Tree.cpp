// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


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
    TreeNode *create(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;

        int mid = (l + r) / 2;

        TreeNode *node = new TreeNode(nums[mid]);

        node->left = create(nums, l, mid - 1);
        node->right = create(nums, mid + 1, r);

        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        TreeNode *root = create(nums, l, r);

        return root;
    }
};