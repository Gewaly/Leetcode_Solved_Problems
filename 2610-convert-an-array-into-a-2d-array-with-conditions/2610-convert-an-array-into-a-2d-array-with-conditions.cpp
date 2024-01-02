class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = 0;
        map<int, int> mp;
        for(auto i : nums) mp[i]++, n = max(n, mp[i]);
        vector<vector<int>> ans(n);
        for(auto [num, f] : mp){
            for(int i = 0;i < f;i++) ans[i].push_back(num);
        }
        return ans;
    }
};