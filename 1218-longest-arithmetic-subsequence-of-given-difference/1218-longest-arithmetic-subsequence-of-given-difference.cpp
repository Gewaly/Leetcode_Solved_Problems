class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
         unordered_map<int,int>dp;
    int ans=1;
    for(int i=0;i<arr.size();i++){
        int prev=dp.count(arr[i]-difference)?dp[arr[i]-difference]:0; 
        dp[arr[i]] = prev + 1;
        ans = max(ans, dp[arr[i]]);

    }
        return ans;
    }
};