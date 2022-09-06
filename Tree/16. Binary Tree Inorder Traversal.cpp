// https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Method - 1 (DFS)
// Time Complexity : O(n)
// Space Complexity : O(h)
class Solution
{
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            v.push_back(root->val);
            inorderTraversal(root->right);
        }
        return v;
    }
};

// Method - 2
// BFS
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> st;

        while (root or !st.empty())
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                v.push_back(root->val);
                root = root->right;
            }
        }
        return v;
    }
};