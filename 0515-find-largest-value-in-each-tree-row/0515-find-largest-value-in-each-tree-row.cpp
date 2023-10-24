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

    vector <int> res;
    void traverse(TreeNode* root, int currlevel, int &maxlevel){
        if(!root) return;
        if(currlevel > maxlevel){
            maxlevel = currlevel; 
            res.push_back(root->val);
        }
      
        res[currlevel] = max(res[currlevel], root->val); 
        traverse(root->left, currlevel+1, maxlevel); 
        traverse(root->right, currlevel+1, maxlevel);
    }
    vector<int> largestValues(TreeNode* root) {
        res.clear();
        int maxlevel = -1;
        traverse(root, 0, maxlevel);
        return res;
    }
};