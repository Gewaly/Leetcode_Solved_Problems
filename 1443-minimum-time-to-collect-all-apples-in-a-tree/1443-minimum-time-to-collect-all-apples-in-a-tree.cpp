class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> graph(n);

    for ( vector<int>& edge : edges) {
       int u = edge[0];
       int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    return dfs(graph, 0, vector<bool>(n), hasApple);
  }

 private:
  int dfs( vector<vector<int>>& graph, int u, vector<bool>&& seen,
           vector<bool>& hasApple) {
    seen[u] = true;
    int totalCost = 0;

    for ( int v : graph[u]) {
      if (seen[v])
        continue;
       int cost = dfs(graph, v, move(seen), hasApple);
      if (cost > 0 || hasApple[v])
        totalCost += cost + 2;
    }

    return totalCost;
  }
};