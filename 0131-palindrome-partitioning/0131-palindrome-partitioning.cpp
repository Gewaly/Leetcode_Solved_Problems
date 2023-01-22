class Solution {
public:
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
        vector<string>v={};
        fnc(s,v,ans);
        return ans;
        
    }
    void fnc( string s,vector<string>v,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(v);
            return;
            }
        for(int i=1;i<=s.size();i++){
            string x=s.substr(0,i);
            if(isPalindrome(x)){
                v.push_back(x);
                string y=s.substr(i,s.size()-i);
                fnc(y,v,ans);
                v.pop_back();
            }
        }
        
        }
    bool isPalindrome(string g){
        string t=g;
        reverse(t.begin(),t.end());
        return g==t;
    }
    
    
};