class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(),res.end());
        for(auto x: res) cout<<x<<" ";
        if(res.size()&1) return res[res.size()/2];
        else return (double)(res[res.size()/2]+res[(res.size()-1)/2])/2;
    }
};