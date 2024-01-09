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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        findLeaves(root1, leaves1);
        findLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
    void findLeaves(TreeNode* node, vector<int>& vec){
        if(node == nullptr)return;
        if(node->left != nullptr)
            findLeaves(node->left, vec);
        if(node->right != nullptr)
            findLeaves(node->right, vec);
        if(node->left == nullptr && node->right == nullptr)
            vec.push_back(node->val);
    }
};





