class Solution {
public:
    bool isPathCrossing(string path) {
        vector<int> point = {0, 0};
        map<vector<int>, bool> visited;
        visited[point] = true;
        int n = path.size();
        for(int i=0; i<n; i++){
            if(path[i] == 'N'){
                point[1] += 1;
            }
            else if(path[i] == 'S'){
                point[1] -= 1;
            }
            else if(path[i] == 'E'){
                point[0] += 1;
            }
            else if(path[i] == 'W'){
                point[0] -= 1;
            }

            if(visited[point] == true){
                return true;
            }
            visited[point] = true;

        }

        return false;
    }
};