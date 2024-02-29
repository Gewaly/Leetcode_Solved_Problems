class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;

        while(!q.empty()){
            int size = q.size(), last, curr;

            level++;
            if(level&1) last = INT_MAX;
            else last = INT_MIN;

            while(size--){
                auto top = q.front(); q.pop();
                curr = top -> val;
                
                if(level&1){
                    if(curr >= last || curr%2 == 1) return false;
                }
                else{
                    if(last >= curr || curr%2 == 0) return false;
                }

                last = curr;
                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
            }
        }

        return true;
    }
};