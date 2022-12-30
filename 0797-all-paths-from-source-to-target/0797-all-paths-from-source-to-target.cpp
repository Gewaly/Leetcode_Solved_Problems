#define pb push_back
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int u,vector<vector<int>> &adj,vector<int> &v){
        
        if(u==adj.size()-1){
            ans.pb(v);
        }
        
        for(int i=0;i<adj[u].size();i++){
            v.pb(adj[u][i]);
            dfs(adj[u][i],adj,v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        
        vector<int> v;
        ans.clear();
        v.pb(0);
        dfs(0,adj,v);
        return ans;
    }
};