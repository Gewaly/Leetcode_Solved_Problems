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
class Solution {
public:
    int dfs(bool& res, TreeNode* root, int count) {
        if (!root) return count;
        count++;
        int left = dfs(res, root->left, count);
        int right = dfs(res, root->right, count);
        res &= (abs(left - right) <= 1);
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool res = 1;
        int n = dfs(res, root, 0);
        return res;
    }
};