class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long zero=0,neg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero=1;
            else if(nums[i]<0)
            neg++;
        }
        
        if(zero==1) return 0;
        else if(neg%2==0) return 1;
        return -1;
    }
};