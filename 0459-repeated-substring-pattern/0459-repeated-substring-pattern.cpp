class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s+s;
        string ans="";
        for(int i=1;i<t.size()-1;i++){
        ans+=t[i];
        }
        //cout<<ans;
        if(ans.find(s)!=-1) return true;
        else return false;
    }
};