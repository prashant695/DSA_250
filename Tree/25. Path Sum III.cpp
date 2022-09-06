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
    int res = 0;
    void path(TreeNode *root, int targetSum)
    {
        if (root)
        {
            if (root->val == targetSum)
                res++;
            path(root->left, targetSum - root->val);
            path(root->right, targetSum - root->val);
        }
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root)
        {
            path(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return res;
    }
};

// Similar to find the number of subarrays whose sum is equal to k

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
    int cnt = 0;
    unordered_map<int, int> m;
    void dfs(TreeNode *root, int targetSum, int sum, vector<int> v)
    {
        if (!root)
            return;

        sum += root->val;

        if (m[sum - targetSum])
            cnt += m[sum - targetSum];
        
        m[sum]++;
        
        dfs(root->left, targetSum, sum, v);
        dfs(root->right, targetSum, sum, v);
        
        m[sum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        vector<int> v;
        m[0] = 1;
        dfs(root, targetSum, 0, v);
        return cnt;
    }
};