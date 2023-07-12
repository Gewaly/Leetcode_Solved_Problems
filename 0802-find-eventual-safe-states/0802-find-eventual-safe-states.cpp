class Solution {
public:
    bool dfsCheck(int start,vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis,vector<int> &check){
        vis[start] = 1;
        pathVis[start] = 1;
        check[start] = 0;
        for(auto it:adj[start]){
            if( vis[it] == 0 ){
                if(dfsCheck(it,adj,vis,pathVis,check)){
                    check[start] = 0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[start] = 0;
                return true;
            }
        }
        check[start] = 1;
        pathVis[start] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0), pathVis(n,0),check(n,0),ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsCheck(i,adj,vis,pathVis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};