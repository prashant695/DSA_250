// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        push(root);
    }

    int next()
    {
        TreeNode *t = s.top();
        s.pop();
        push(t->right);
        return t->val;
    }

    bool hasNext()
    {
        return s.empty() == false;
    }

    void push(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
};
