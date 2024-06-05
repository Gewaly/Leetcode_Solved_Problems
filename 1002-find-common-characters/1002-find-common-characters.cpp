class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
    map<char,int> mp,kp;
    for(auto it:words[0]){ 
        mp[it]++; 
    }
    for(int i=1;i<words.size();i++){
        map<char,int> kp;
        for(auto it:words[i]){   
            kp[it]++;
        } 
        for(auto it:mp){
            mp[it.first]=min(kp[it.first],it.second); 
        } 
    } 
    vector<string> ans; 
    for(auto &it:mp){ 
        string s(1,it.first);
        while(it.second>0){ 
            it.second--;
            ans.push_back(s);
        }
    } 
    return ans;
    }
};