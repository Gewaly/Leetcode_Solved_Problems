#define st first
#define nd second
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        int n=tasks.size(),cnt=0;
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        for(auto x:mp){
            if(x.nd==1) return -1;
            if(x.nd%3==0)
                cnt+=x.nd/3;
            else cnt+=x.nd/3+1;
                
        }
        return cnt;
    }
};