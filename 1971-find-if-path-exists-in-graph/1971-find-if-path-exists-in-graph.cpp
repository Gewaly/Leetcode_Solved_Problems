class Solution {
public:
    bool validPath(int  n, vector<vector<int >>& edges, long long source, int  destination) {
        if(edges.size() == 0)  return true;

        
        unordered_map<int,list<int>> adjList;
                                                                                    
        int m = edges.size();
                                                                                    
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        unordered_map<int,bool> mp;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto i : adjList[front]){
                if(mp[i] == false){
                    q.push(i);
                    mp[i] = true;
                }
            }
        }
        
       
        
        return mp[destination];

        
    }
};