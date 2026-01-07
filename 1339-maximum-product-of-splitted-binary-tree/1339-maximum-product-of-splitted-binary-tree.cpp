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
    long long maxProduct(TreeNode* root) {
        long long Total=total_sum(root);
        long long ans=0;
        prod(root,Total,ans);
        return ans%1000000007;
    }

    long long total_sum(TreeNode* root){
        if(!root) return 0;
        return total_sum(root->right)+total_sum(root->left)+root->val;  
    }
    long long prod(TreeNode* root,long long Total,long long& ans){
        if(!root) return 0;
        long prodsum=0;
        prodsum+=prod(root->left,Total,ans);
        prodsum+=prod(root->right,Total,ans);
        prodsum+=root->val;
        //ans=max(ans,(Total-prodsum)*prodsum);
        if(ans<(Total-prodsum)*prodsum)
           ans=(Total-prodsum)*prodsum;
        return prodsum;
    }



};