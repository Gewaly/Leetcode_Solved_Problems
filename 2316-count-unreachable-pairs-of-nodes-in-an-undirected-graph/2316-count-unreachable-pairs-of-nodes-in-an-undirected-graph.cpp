class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int& nodesInComponent, int node){
        vis[node]=true;
        ++nodesInComponent; // number of nodes in current component
        for(int e:adj[node]){
            if(!vis[e]) dfs(adj,vis,nodesInComponent,e);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n); // adjacency matrix to store all the nodes having direct connection to current node
        long long count=0,rem=n;
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false); 
        for(int i=0;i<n;++i){
            int c=0;
            if(!vis[i]){ // if not visited, call dfs to mark nodes visited and increase the count
                dfs(adj,vis,c,i);
                count+=(rem-c)*c;
                rem-=c;
            }
        }
        return count;
    }
};