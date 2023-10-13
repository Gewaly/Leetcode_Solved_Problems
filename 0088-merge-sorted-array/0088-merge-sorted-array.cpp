class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       multiset<int>mul;
          for(int i=0;i<m;i++){
            mul.emplace(nums1[i]);
        }
        for(int i=0;i<n;i++){
            mul.emplace(nums2[i]);
        }
        nums1.resize(n+m);
        int v=0;
        for(auto it:mul ){
            nums1[v]=it;
            v++;
                }
    for(int i=0;i<(n+m);i++) cout<<nums1[i];
        

    }
};