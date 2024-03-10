class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans,res;
        for(auto x: nums1){
            for(auto y: nums2){
                if(x==y) res.push_back(x);
            }
        }
        set<int>s;
        for(auto x: res){
            s.emplace(x);
        }
        for(auto y: s){
            ans.push_back(y);
        }
        
        return ans;
        
    }
};