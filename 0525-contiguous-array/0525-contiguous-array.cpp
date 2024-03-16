class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i = 0 ; i < nums.size();i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        int sum = 0;
        int ans = 0 ;
        for(int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            if(sum==0)
            {
                ans = max(ans,i+1); 
            }   
            if(umap.find(sum) != umap.end())
            {
                ans = max(ans,i-umap[sum]);
            }        
            else
            {
                umap[sum]=i;
            }
        }
        return ans ;
    }
};