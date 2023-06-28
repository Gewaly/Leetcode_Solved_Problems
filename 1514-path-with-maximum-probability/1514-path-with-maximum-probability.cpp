class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
         double result = 0;
         if(start == end) return (double)1;
         vector<pair<int , double>> adj[n];
         for(int i = 0 ; i < edges.size() ; i++)
         {
             int u = edges[i][0];
             int v = edges[i][1];

             double prob = abs(log10(succProb[i]));
             adj[u].push_back({v , prob});
             adj[v].push_back({u , prob});
         }
         vector<double> distance(n , INT_MAX);
         distance[start] = 0;
         queue<int> q;
         q.push(start);
         while(q.size())
         {
             int node = q.front();
             q.pop();
             for(auto x : adj[node])
             {
                 int node2 = x.first;
                 double wt = x.second;

                 if(distance[node2]==INT_MAX || distance[node]+wt < distance[node2])
                 {
                     distance[node2] = distance[node] + wt;
                     q.push(node2);
                 }
             }
         }
         if(distance[end] == INT_MAX) return (double)0;
         return double(pow(10 , -1*distance[end]));
         return 0;
    }
};