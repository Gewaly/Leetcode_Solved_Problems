class Solution {
public:
     void dfs(int node , vector<int>adj[],vector<int>&vis){
         vis[node] = 1;
         for(auto i : adj[node]){
             if(vis[i] == 0){
                 dfs(i,adj,vis);
             }
         }
     }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && v[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                c++;
                dfs(i,adj,vis);
            }
        }
        return c;
    }
};