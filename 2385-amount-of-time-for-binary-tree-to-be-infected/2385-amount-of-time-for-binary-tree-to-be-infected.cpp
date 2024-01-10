/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right
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
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* startNode;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(temp->val==start)
            {
                startNode=temp;
            }
            if(temp->left!=NULL)
            {
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }

        queue<TreeNode*>qu;
        qu.push(startNode);
        map<TreeNode*,int>vis;
        vis[startNode]=1;
        int ans=0;
        while(!qu.empty())
        {
            int n=qu.size();
            int change=0;
            for(int i=0;i<n;i++)
            {
                auto temp=qu.front();
                qu.pop();
                
                if(temp->left and !vis[temp->left])
                {
                    qu.push(temp->left);
                    vis[temp->left]=1;
                    change++;
                }
                if(temp->right and !vis[temp->right])
                {
                    qu.push(temp->right);
                    vis[temp->right]=1;
                    change++;
                }
                if(parent[temp] and !vis[parent[temp]])
                {
                    qu.push(parent[temp]);
                    vis[parent[temp]]=1;
                    change++;
                }
            }
            

            if(change) ans++;
        }

        return ans;

        
    }
};