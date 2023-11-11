class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph = vector<vector<pair<int, int>>>(n);
        for (auto& edge : edges) addEdge(edge);
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> costs(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        costs[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [curr_cost, curr_node] = pq.top();
            pq.pop();
            for (auto [next_node, next_cost] : graph[curr_node]) {
                int cost = curr_cost + next_cost;
                if (cost >= costs[next_node]) continue;
                costs[next_node] = cost;
                pq.push({cost, next_node});
            }
        }
        
        if (costs[node2] == INT_MAX) return -1;
        return costs[node2];
    }
private:
    int n;
    vector<vector<pair<int, int>>> graph;       
};


/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */