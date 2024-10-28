class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long,int>mp;
        int cnt=0;
        for(auto& it:nums)
        mp[it]++;

        for(auto& it:nums)
        {
            int temp=1,num=it;
            while(1)
            {
                long long mul=1LL*num*num;
                if(mp.find(mul)==mp.end())
                break;

                temp++;
                num=mul;
            }
            cnt=max(cnt,temp);
        }
        return cnt==1?-1:cnt;
    }
};