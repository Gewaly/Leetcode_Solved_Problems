/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root->val > max(p->val, q->val) or root->val < min(p->val, q->val)) {
            if (root->val < min (p->val, q->val)) root = root->right;
            else root = root->left;
        }
        return root;
    }
};