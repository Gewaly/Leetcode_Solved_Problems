class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v = nums;
        int ans = nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push({v[0], 0});
        for(int i = 1; i < n; i++){
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            v[i] = max(v[i], nums[i] + pq.top().first);
            pq.push({v[i], i});
            ans = max(ans, v[i]);
        }
        return ans;
    }
};