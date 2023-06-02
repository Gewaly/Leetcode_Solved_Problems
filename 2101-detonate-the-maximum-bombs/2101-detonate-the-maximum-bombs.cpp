class Solution {
public:
void dfs(int start,vector<int>&vis,vector<int>adj[],int &count){
    vis[start]=1;
    count++;
    for(auto it:adj[start]){
        if(!vis[it]){
            dfs(it,vis,adj,count);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans= INT_MIN;
        int n= bombs.size();
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                long long x1=bombs[i][0];
                long long y1=bombs[i][1];
                long long r1= bombs[i][2];
                if(i!=j){
                    long long x= abs(x1-bombs[j][0]);
                    long long y= abs(y1-bombs[j][1]);
                    if(x*x+y*y<=r1*r1){
                        adj[i].push_back(j);


                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            int count=0;
            vector<int>vis(n,0);
            dfs(i,vis,adj,count);
            ans= max(ans,count);
        }
        return ans;
        
    }
};