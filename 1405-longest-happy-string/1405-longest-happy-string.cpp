class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string ans;
        while (!pq.empty()) {
            auto it1 = pq.top();
            pq.pop();
            if (ans.size()>=2 && ans.back()==it1.second && ans[ans.size()-2]==it1.second) {
                if (pq.empty()) break;
                auto it2 = pq.top();
                pq.pop();
                ans.push_back(it2.second);
                it2.first--;
                if (it2.first > 0) pq.push(it2);
                pq.push(it1);
            } else {
                ans.push_back(it1.second);
                it1.first--;
                if (it1.first > 0) pq.push(it1);
            }
        }
        return ans;
    }
};