class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        queue<int> Q;
        int lst = 0, end = -1, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]&1){
                Q.push(i);
            }
            if(Q.size() == k){
                lst = end;
                end = Q.front();
                Q.pop();
            }
            if(end != -1){
                ans += end - lst;
            }
        }
        return ans;
    }
};