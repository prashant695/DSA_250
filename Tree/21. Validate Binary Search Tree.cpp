// https://leetcode.com/problems/validate-binary-search-tree/

// Method - 1
// Bruteforce
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
    vector<int> v;
    set<int> s;
    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            v.push_back(root->val);
            s.insert(root->val);
            dfs(root->right);
        }
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> v2;
        dfs(root);
        v2 = v;
        sort(v2.begin(), v2.end());
        return (v == v2 && s.size() == v.size());
    }
};

// Method - 2

class Solution
{
public:
    long long prev = LONG_LONG_MAX;
    vector<int> v;
    int flg = 1;
    void in(TreeNode *root)
    {
        if (root)
        {
            in(root->left);
            if (prev != LONG_LONG_MAX)
            {
                if (root->val - prev <= 0)
                    flg = 0;
            }
            prev = root->val;
            in(root->right);
        }
    }
    bool isValidBST(TreeNode *root)
    {
        in(root);
        return flg;
    }
};

// Method - 3

class Solution
{
public:
    bool valid(TreeNode *root, long min, long max)
    {
        if (!root)
            return 1;

        if (root->val <= min or root->val >= max)
            return 0;

        return valid(root->left, min, root->val) and
               valid(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root)
    {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};