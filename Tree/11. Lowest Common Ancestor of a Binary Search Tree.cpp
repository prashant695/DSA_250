// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Method - 1
// Store the path

class Solution
{
public:
    bool in(TreeNode *root, TreeNode *p, vector<TreeNode *> &v)
    {
        if (root == NULL)
            return 0;

        v.push_back(root);
        if (root == p)
        {
            return 1;
        }

        if (in(root->left, p, v) or in(root->right, p, v))
            return 1;

        v.pop_back();

        return 0;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> v;
        in(root, p, v);

        vector<TreeNode *> v2;
        in(root, q, v2);

        TreeNode *x;

        for (int i = 0; i < min(v.size(), v2.size()); i++)
        {
            if (v[i] != v2[i])
                return x;
            x = v[i];
        }
        if (v.size() < v2.size())
            return v[v.size() - 1];
        return v2[v2.size() - 1];
    }
};

// Method - 2
// Using BST Property


class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (root->val < p->val && root->val > q->val)
                return root;

            else if (root->val > p->val && root->val < q->val)
                return root;
            
            else if (root->val == p->val || root->val == q->val)
                return root;
            
            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }
};