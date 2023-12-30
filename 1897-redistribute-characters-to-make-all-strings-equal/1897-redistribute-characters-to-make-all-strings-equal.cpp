class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        if(words.size()==1) return true;
        for(int i=0;i<words.size();i++){
            string s =words[i];
            for(int j=0;j<s.size();j++){
                mp[s[j]]++;
            }   
        }
        for(auto x: mp){
            if(x.second%words.size()!=0) return false;
        }
        return true;
        
    }
};