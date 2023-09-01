class Solution {
public:
    vector<int> countBits(int n) {
     vector<int>ans;
        int cnt;
        for(int i=0;i<=n;i++){
            cnt=0;
              for (int j = 31; j >= 0; j--) {
        int k = i >> j;
        if (k & 1)
            cnt++;
        }
        ans.push_back(cnt);
        }  
        return ans;
    }
};