class Solution {
    public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(N+1,0);
        //connect the graph
        for (auto item: dislikes){
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }
        queue<int> que;
        //check neighber
        for (int i=1; i<N+1; i++){
            if (visited[i]==0){
                visited[i]=1;
                que.push(i);
                while (!que.empty()){
                    int curPos=que.front(); que.pop();
                    for (auto neighber: graph[curPos]){
                        if (visited[neighber]==0){ 
                            visited[neighber]= (visited[curPos]==1)? 2:1;
                            que.push(neighber);
                        }
                        else if (visited[neighber]==visited[curPos]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};