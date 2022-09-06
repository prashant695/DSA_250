// https://leetcode.com/problems/symmetric-tree/

// Method 1 (O(n^2))

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
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> q;

        q.push(root);
        string s;
        s += root->val + '0';
        while (q.size())
        {
            int len = q.size();
            s = " ";
            while (len--)
            {
                TreeNode *cur = q.front();
                q.pop();

                if (cur->left)
                    q.push(cur->left), s += cur->left->val + '0';
                else
                    s += '&';

                if (cur->right)
                    q.push(cur->right), s += cur->right->val + '0';
                else
                    s += '&';
            }

            if (!isPalindrome(s))
                return false;
        }
        return true;
    }
};

// Method 2 (optimised)

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
    bool help(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;

        else if (!p or !q)
            return false;
        
        else if (p->val != q->val)
            return false;
        else
            return (help(p->left, q->right) && help(q->left, p->right));
    }
    bool isSymmetric(TreeNode *root)
    {
        return help(root, root);
    }
};
