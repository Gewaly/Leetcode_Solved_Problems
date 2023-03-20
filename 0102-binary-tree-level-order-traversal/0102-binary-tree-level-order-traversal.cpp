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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        // Base Case
    if (root == NULL)
        return res;
 
    // Create an empty queue for level order traversal
    queue<TreeNode*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
                   int sz=q.size();
                vector<int>ans;
        // Print front of queue and remove it from queue
         while(sz--){
        TreeNode* node = q.front();
        // cout << node->data << " ";
          ans.push_back(q.front()->val);
               q.pop();
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
      
    }
           res.push_back(ans);

    
    }
        return res;
    }
};