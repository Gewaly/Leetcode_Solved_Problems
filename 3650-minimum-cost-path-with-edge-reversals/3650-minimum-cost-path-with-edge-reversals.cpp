class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, 2 * cost});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int d = pq.top().first; 
            int u = pq.top().second;
            pq.pop();
            
            if(u == n - 1) return d;

            for(auto& edge : adj[u]){
                int v = edge.first;
                int weight = edge.second;
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v],v});
                }
            }
        }
        return -1;
    }
};