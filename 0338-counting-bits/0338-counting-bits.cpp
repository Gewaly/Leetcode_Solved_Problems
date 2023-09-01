class Solution {
public:
    vector<int> countBits(int n) {
     vector<int>ans;
        int cnt;
        for(int i=0;i<=n;i++){
            int cnt=__builtin_popcount(i);
            ans.push_back(cnt);
        }  
        return ans;
    }
};