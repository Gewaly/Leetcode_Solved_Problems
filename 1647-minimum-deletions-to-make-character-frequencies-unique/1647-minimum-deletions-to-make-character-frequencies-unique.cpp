class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        map<int,int>mp2;
        int cnt=0;
        for(auto x: mp) {
            if(mp2[x.second]!=1){ mp2[x.second]=1;}
            else {
                while(mp2[x.second]==1 && x.second>0){ x.second--; cnt++; }
                mp2[x.second]=1;
                }
        
        }
           
        return cnt;
    }
};