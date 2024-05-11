class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> rq;
        for(int i = 0; i < quality.size(); ++i) {
            rq.push_back({double(wage[i])/quality[i], quality[i]});
        }
        sort(rq.begin(), rq.end());
        priority_queue<int> pq;
        int sum = 0;
        double ans = DBL_MAX;
        for(auto i: rq){
            sum += i.second;
            pq.push(i.second);
            if(pq.size() > k)  { sum -= pq.top(); pq.pop(); } 
            if(pq.size() == k) { ans = min(ans, sum*i.first); }
        }
        return ans;
    }
};