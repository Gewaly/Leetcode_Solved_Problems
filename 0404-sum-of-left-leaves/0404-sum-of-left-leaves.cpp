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
    bool isleaf(TreeNode* root){
        if(!root) return false;
        if(root->left==nullptr && root->right==nullptr) return true;
        return false;
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(root!=nullptr){
            if(isleaf(root->left)) ans+=root->left->val;
            else 
                ans+=sumOfLeftLeaves(root->left);
                    ans += sumOfLeftLeaves(root->right);

        }
        return ans;
    }
};