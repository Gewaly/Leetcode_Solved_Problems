class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(),cols = heights[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> minHeap;

        minHeap.emplace(0,0,0);

        dist[0][0] = 0;

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!minHeap.empty()){
            auto [efforts,x,y] = minHeap.top();
            minHeap.pop();

            if(efforts > dist[x][y]) continue;

            if(x == rows-1 and y == cols - 1) return efforts;

            for(auto &dir:dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int new_effort = max(efforts, abs(heights[x][y] - heights[nx][ny]));
                    if (new_effort < dist[nx][ny]) {
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};