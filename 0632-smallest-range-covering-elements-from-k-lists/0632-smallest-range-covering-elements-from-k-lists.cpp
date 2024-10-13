class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=nums.size(),maxi=-1e9;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],i,0});
            maxi=max(maxi,nums[i][0]);
        }
        int left,right,range=1e9;
        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            int mini=it[0],i=it[1],j=it[2];
            if(maxi-mini<range){
                left=mini;
                right=maxi;
                range=maxi-mini;
            }
            if(j>=nums[i].size()) break;
            pq.push({nums[i][j],i,j+1});
            maxi=max(maxi,nums[i][j]);
        }
        return {left,right};
    }
};