class Solution {
public:
    void print(TreeNode* root,int k,vector<int>& ans){
        if(root==nullptr or k<0)
            return;
        if(k==0)
            ans.push_back(root->val);
        else{
            print(root->left,k-1,ans);
            print(root->right,k-1,ans);
        }
        return;
    }
    int help(TreeNode* root,TreeNode* target, int k,vector<int>& ans){
        if(root==nullptr)
            return -1;
        else if(root->val==target->val){
            print(target,k,ans);
            return 0;
        }
        int left=help(root->left,target,k,ans);
        if(left!=-1){
            if(left+1==k)
                ans.push_back(root->val);
            else
                print(root->right,k-left-2,ans);
            return left+1;
        }
        int right=help(root->right,target,k,ans);
        if(right!=-1){
            if(right+1==k)
                ans.push_back(root->val);
            else
                print(root->left,k-right-2,ans);
            return right+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        help(root,target,k,ans);
        
        return ans;
        
    }
};