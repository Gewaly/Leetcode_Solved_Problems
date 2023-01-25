class Solution {
public:
    vector<int>dijkstra(vector<vector<pair<int,int>>>&adj,int node){
        int n=adj.size();
        vector<int>vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,node});
        vector<int>dis(n,INT_MAX);
        dis[node]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int nd=pq.top().second;
            pq.pop();
            for(auto it:adj[nd]){
                if(dis[it.first]>(it.second+dist)){
                    dis[it.first]=it.second+dist;
                    pq.push({it.second+dist,it.first});
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            adj[i].push_back({edges[i],1});
            
        }
        vector<int>dis1=dijkstra(adj,node1);
        vector<int>dis2=dijkstra(adj,node2);
        int ans=INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++){
            if(max(dis1[i],dis2[i])<ans){
                ans=max(dis1[i],dis2[i]);
                index=i;
            }
        }
        return index;
       
    }
};