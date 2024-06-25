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
    void inOrderRevrse(TreeNode* root,int&sum){
        if(!root)return;
        if(!root->left && !root->right){
            root->val+=sum;
            sum=root->val;
            return;
        }
        inOrderRevrse(root->right,sum);
        root->val+=sum;
        sum=root->val;
        inOrderRevrse(root->left,sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        inOrderRevrse(root,sum);
        return root;
    }
};