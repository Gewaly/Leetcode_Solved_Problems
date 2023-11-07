class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        set<int>s;
        for(auto x: mp){
            s.emplace(x.second);
        }
        return(s.size()==mp.size());
        
    }
};