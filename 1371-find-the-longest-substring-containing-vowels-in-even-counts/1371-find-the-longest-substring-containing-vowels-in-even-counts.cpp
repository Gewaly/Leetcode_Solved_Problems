class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        int xr = 0;
        int maxi=0;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i]=='u'){
                xr = xr ^ s[i];
            }

            if(xr==0){
                maxi=max(maxi,i+1);
            }

            int rem = xr;

            if(mp.find(rem)!=mp.end()){
                maxi=max(maxi,i-mp[xr]);
            }
            
            if(mp.find(xr) == mp.end()){
                mp[xr]=i;
            }
        }
        return maxi;

    }
};