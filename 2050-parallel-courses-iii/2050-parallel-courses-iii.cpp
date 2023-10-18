class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2){
        if(v1[0] < v2[0]) return true;
        if(v1[0] == v2[0] && v1[1] < v2[1]) return true;
        return false;
    }

    vector<vector<int>> v;
    vector<int> dp;

    int dfs(int n, vector<int>& time){
        if(dp[n] != -1) return dp[n];
        dp[n] = 0;
        for(int p : v[n]){
            dp[n] = max(dp[n], dfs(p, time));
        }
        dp[n] += time[n];
        return dp[n];
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        //sort(relations.begin(), relations.end(), compare);
        v = vector<vector<int>>(n);
        for(vector<int>& r : relations){
            v[r[1]-1].push_back(r[0]-1);
        }
        dp = vector<int>(n, -1);
        for(int i = 0; i < n; i++){
            dp[i] = dfs(i, time);
            //printf("%d\n", dp[m.first]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};