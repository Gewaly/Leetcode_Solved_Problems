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
    TreeNode* removeLeafNodes(TreeNode* ptr, int t) {
        if(ptr->left) ptr->left=removeLeafNodes(ptr->left,t);
        if(ptr->right) ptr->right=removeLeafNodes(ptr->right,t);
        if(ptr->left==NULL&&ptr->right==NULL&&ptr->val==t) return NULL;
        return ptr;
    }
};
