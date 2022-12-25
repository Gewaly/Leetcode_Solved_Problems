class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>par(nums.size());
            vector<int>res;
        sort(nums.begin(),nums.end());
            
            // partial_sum(nums.begin(), nums.end(), par);
        for(int i=0;i<nums.size();i++){
            if(i==0) par[i]=nums[i];
            else par[i]=nums[i]+par[i-1];
        }
               //int cnt=0;
           for(int i=0;i<queries.size();i++){
               int ans=upper_bound(par.begin(),par.end(),queries[i])-par.begin();
               res.push_back(ans);
           } 
    

              
        
        return res;
    }
};