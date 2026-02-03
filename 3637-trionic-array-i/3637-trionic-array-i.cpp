class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size() < 4 || nums[1] <= nums[0]) return false;
        int dec = 0, inc = 0;
        int flag = 0;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) return false;
            if(flag == 0 && nums[i] < nums[i-1]) {
                dec++;
                flag = 1;
            } 
            else if(flag && nums[i] > nums[i-1]) {
                inc++;
                flag = 0;
            }
        }

        return dec == 1 && inc == 1;
    }
};