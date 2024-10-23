using ll = long long;
void dfs(TreeNode *root,vector<ll> &arr,int lev){
    if(root == NULL) return;
    root->val = arr[lev] - root->val;
    if(root->left) dfs(root->left,arr,lev+1);
    if(root->right) dfs(root->right,arr,lev+1);
}
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<ll> arr;
        arr.push_back(root->val);
        while(!q.empty()){
            int l = q.size();
            ll ans = 0;
            for(int i=0;i<l;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    ans+=temp->left->val;
                    q.push(temp->left);
                }
                if(temp->right){
                    ans+=temp->right->val;
                    q.push(temp->right);
                }
                if(temp->left && temp->right){
                    temp->left->val+=temp->right->val;
                    temp->right->val = temp->left->val;
                }
            }
            arr.push_back(ans);
        }
        dfs(root,arr,0);
        return root;
    }
};