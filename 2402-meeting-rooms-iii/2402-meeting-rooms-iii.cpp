class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> occupied;
        priority_queue<long, vector<long>, greater<long>> free;
        for(int i = 0 ; i < n; i++) {
            free.push(i);
        }
        vector<int> counter(n);
        sort(meetings.begin(), meetings.end());
        for(auto meet : meetings) {
            int index = 0;
            while(!occupied.empty() && occupied.top().first <= meet[0]) {
                free.push(occupied.top().second);
                occupied.pop();
            }
            if(!free.empty()) {
                index = free.top();
                occupied.push({meet[1], free.top()});
                free.pop();
            } else {
                auto curr = occupied.top();
                index = curr.second;
                curr.first = curr.first + (meet[1]- meet[0]);
                occupied.pop();
                occupied.push(curr);
            }
            counter[index]++;
        }
        int ans = 0, maxValue = 0;
        for(int i = 0; i < n; i++) {
            if(maxValue < counter[i]) {
                maxValue = counter[i];
                ans = i;
            }
        }
        return ans;
    }
};