class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int o=0,z=0,ans=0,j=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) z++;
            else o++;
            while(z>k) nums[j++]==0 ? z--:o--;
            ans = max(ans,o+z); 
        }
        return ans;
    }
};