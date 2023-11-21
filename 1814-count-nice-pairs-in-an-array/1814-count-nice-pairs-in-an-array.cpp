class Solution {
public:

    int rev(int x){
        int res = 0;
        while(x > 0){
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(int num : nums){
            int revNum = rev(num);
            int diff = num - revNum;
     
            if(mp.find(diff) != mp.end()){
                ans = (ans + mp[diff])%1000000007;
    }
            mp[diff]++;
        }
        return ans;
    }
};