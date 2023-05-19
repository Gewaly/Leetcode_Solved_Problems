class Solution {
public:
    bool solve(int s,int x,vector<int> &v,vector<vector<int>> &g){
        if(v[s]!=-1){
            if(v[s] != x)return false;
            return true;
        }
        v[s] = x;
        bool ans = true;
        for(auto &i: g[s]){
            ans &= solve(i,x^1,v,g);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(),i;
        vector<int> v(n,-1);
        vector<vector<int>> g(n);
        for(i = 0; i < n; i++){
            for(auto &j: graph[i]){
                g[i].push_back(j);
            }
        }
        bool ans = true;
        for(i = 0; i < n; i++){
            if(v[i]==-1){
                ans &= solve(i,0,v,g);
            }
        }
        return ans;
    }
};