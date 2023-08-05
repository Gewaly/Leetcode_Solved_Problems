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
    vector<vector<vector<TreeNode*>>> dp;
    
    vector<TreeNode*> BSTree(int s, int e){
        if (s > e) return {NULL};
        if (s == e) return {new TreeNode(s)};
        
        if (dp[s][e].size()>0) return dp[s][e];
        
        vector<TreeNode*> ans;
        for (int j = s; j <= e; j++) {
            vector<TreeNode*> Left = BSTree(s, j - 1);
            vector<TreeNode*> Right = BSTree(j + 1, e);
            
            for (TreeNode* l : Left) {
                for (TreeNode* r : Right) {
                    TreeNode* root = new TreeNode(j, l, r);
                    ans.push_back(root);
                }
            }
        }
        return dp[s][e] = ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        dp.assign(n+1, vector(n+1, vector<TreeNode*>()));
        return BSTree(1, n);
    }
};