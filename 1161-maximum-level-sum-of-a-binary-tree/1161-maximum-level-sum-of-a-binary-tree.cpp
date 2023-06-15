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
    //bfs
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_sum=INT_MIN;
        int level=0;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            level++;
            int sum=0;
            while(n--){
                sum+=q.front()->val;
                if(q.front()->left!=nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=nullptr){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(max_sum<sum){
                max_sum=sum;
                ans=level;
            }
        }
        return ans;
    }
};