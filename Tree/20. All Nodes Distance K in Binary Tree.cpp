// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> v;
    map<TreeNode *, TreeNode *> parent;
    map<TreeNode *, int> vis;
    void bfs(TreeNode *node, int k)
    {
        if (node && k >= 0 && vis[node] == 0)
        {
            vis[node] = 1;

            if (k == 0)
                v.push_back(node->val);

            bfs(parent[node], k - 1);
            bfs(node->left, k - 1);
            bfs(node->right, k - 1);
        }
    }
    void dfs(TreeNode *root)
    {
        if (root)
        {
            if (root->left)
                parent[root->left] = root;

            if (root->right)
                parent[root->right] = root;

            dfs(root->left);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        dfs(root);
        bfs(target, k);
        return v;
    }
};