class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dst, int target) {
        vector<vector<pair<int, vector<int>*>>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].emplace_back(e[1], &e);
            adj[e[1]].emplace_back(e[0], &e);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, dst);
        vector<int> dd(n, INT_MAX);
        dd[dst] = 0;
        while (!pq.empty()) {
            auto [d_u, u] = pq.top(); pq.pop();
            if (d_u == dd[u]) {
                for (auto& [v, e]: adj[u]) {
                    int w = e->at(2);
                    if (w == -1)
                        w = 1;
                    if (dd[v] > dd[u] + w) {
                        dd[v] = dd[u] + w;
                        pq.emplace(dd[v], v);
                    }
                }
            }
        }
        pq.emplace(0, src);
        vector<int> ds(n, INT_MAX);
        ds[src] = 0;
        while (!pq.empty()) {
            auto [d_u, u] = pq.top(); pq.pop();
            if (d_u == ds[u]) {
                for (auto& [v, e]: adj[u]) {
                    int &w = e->at(2);
                    if (w == -1)
                        w = max(1, target - ds[u] - dd[v]);
                    if (ds[v] > ds[u] + w) {
                        ds[v] = ds[u] + w;
                        pq.emplace(ds[v], v);
                    }
                }
            }
        }
        return ds[dst] == target ? edges : vector<vector<int>>{};
    }
};