class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[++index]=nums[i];
            } 
        }
        return index+1;
    }};