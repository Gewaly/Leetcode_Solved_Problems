class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        vector<int>res;
        for(auto x: mp){
            res.push_back(x.second);
        }
                for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
                }
        
        sort(res.begin(),res.end());
        int ans=res.size();
        for(int i=0;i<res.size();i++){
            if(k>=res[i]){ k-=res[i]; ans--;} 
            else return ans;
        }
        return ans;
    
        
        
    }
};