class Solution {
public:
    bool validPath(int  n, vector<vector<int >>& edges, long long source, int  destination) {
        if(edges.size() == 0)  return true;

        
        //  creating the adjustant list from edges
        unordered_map<int,list<int>> adjList;
                                                                                    
        // no of edges
        int m = edges.size();
                                                                                    
        // making adjustant list
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // creating the visited map and queue for applying BFS algorithm
        unordered_map<int,bool> mp;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            //  storing front element from queue and removing it from queue then
            int front = q.front();
            q.pop();
            
            for(auto i : adjList[front]){
                if(mp[i] == false){
                    q.push(i);
                    mp[i] = true;
                }
            }
        }
        
        // checking if visited array destination position is true or not
        // if it is true means than it means their is possible path 
        
        return mp[destination];

        
    }
};