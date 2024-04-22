class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> mp;
        for (const auto& it : deadends) {
            mp[it] = -1;
        }
        string start = "0000";
        if (target == start)return 0;
        queue<pair<string, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            string src = q.front().first;
            int n = q.front().second;
            q.pop();
            if (src == target)return n;
            if (mp[src] == -1)continue;
            mp[src] = -1;
            for (int i = 0; i < 4; i++) {
                string right = src;
                string left = src;
                right[i] = (right[i] - '0' + 1) % 10 + '0';
                left[i] = (left[i] - '0' + 9) % 10 + '0';
                if (mp[right] != -1)q.push({right, n + 1});
                if (mp[left] != -1)q.push({left, n + 1});
            }
        }
        return -1;
    }
};