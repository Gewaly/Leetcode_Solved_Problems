class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto x: mp) cout<<x.first<<" "<<x.second<<endl;
       int cnt=0,one=0;
        for(auto x: mp){
           if(x.second%2==0) cnt+=x.second;
            else{ cnt+=(x.second-1); one=1;}
       }
    
        if(one) cnt++;
         return cnt;
        
    }
};