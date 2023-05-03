class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        for(int i=0;i<nums1.size();i++) s1.emplace(nums1[i]);
        for(int i=0;i<nums2.size();i++) s2.emplace(nums2[i]);
        vector<int>numss1,numss2;
         for (auto it = s1.rbegin(); it != s1.rend(); ++it)
    {
        numss1.push_back(*it);
    }
           for (auto it = s2.rbegin(); it != s2.rend(); ++it)
    {
        numss2.push_back(*it);
    }
        
     vector<vector<int>>ans(2);
        for(int i=0;i<numss1.size();i++){
            int f=0;
            for(int j=0;j<numss2.size();j++){
                if(numss1[i]==numss2[j]){ f=1; goto w; }
            }
            w:
            if(f==0) ans[0].push_back(numss1[i]);
        }
        for(int i=0;i<numss2.size();i++){
            int f=0;
            for(int j=0;j<numss1.size();j++){
                       if(numss2[i]==numss1[j]){ f=1; goto R; }
            }
            R:
            if(f==0) ans[1].push_back(numss2[i]);
            }
        
     
        return ans;
    }
};