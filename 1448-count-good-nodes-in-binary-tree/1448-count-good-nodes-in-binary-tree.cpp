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
    int goodNodes(TreeNode* root) {
        return fun(root,root->val);
    }
    int fun(TreeNode* root,int value)
    {
        if(root==NULL)
            return 0;
        
        int t=0;
        if(root->val >= value) 
        {
            t++;
            value = root->val;
        }
        
        return t + fun(root->left,value) + fun(root->right,value);
    }
};