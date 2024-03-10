class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        for(auto x: nums1){
            for(auto y: nums2){
                if(x==y) res.push_back(x);
            }
        }
        set<int>s(res.begin(),res.end());
        vector<int>ans(s.begin(),s.end());
        
        
        return ans;
        
    }
};