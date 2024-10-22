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
    long long kthLargestLevelSum(TreeNode* root, int k) {
   priority_queue<long long, vector<long long>, greater<long long>> pq;
      
        queue<TreeNode *> q;
        q.push(root);
        // 5
        // 8 9
        // 2 1 3 7
        while(!q.empty()){
            int sz = q.size();
            long long currSumVal = 0;
            for(int i = 0 ; i < sz ; i++){
                auto front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                currSumVal += front->val * 1LL;
            }
            pq.push(currSumVal);
            if(pq.size() > k) pq.pop();
        }
        return pq.size() < k ? -1LL : pq.top();
    }
};