class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int mx=0;
        for(auto x: mp){
            mx=max(mx,x.second);
        }
        for(auto x: mp){
            if(mx==x.second) return x.first; 
        }
            return 0;
    }
};