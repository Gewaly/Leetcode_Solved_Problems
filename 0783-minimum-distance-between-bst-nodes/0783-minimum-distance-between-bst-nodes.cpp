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
    void inorder(TreeNode* root,vector<int>&arr)
 {
    if(!root) return;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr); 
}
    int minDiffInBST(TreeNode* root) {
        vector<int>arr;
         inorder(root,arr);
        int n=arr.size();
            int diff = INT_MAX;
            for (int i = 0; i < n - 1; i++)
              for (int j = i + 1; j < n; j++)
                  diff=min(diff,abs(arr[i] - arr[j]));
                           
           return diff;                
    }
};