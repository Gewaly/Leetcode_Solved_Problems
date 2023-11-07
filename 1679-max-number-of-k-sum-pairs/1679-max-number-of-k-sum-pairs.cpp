class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,cnt=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            if(nums[l]+nums[r]==k){ cnt++; l++; r--; }
            else if(nums[l]+nums[r]>k){ r--;   }
            else l++;
            
        }
        return cnt;
        
    }
};