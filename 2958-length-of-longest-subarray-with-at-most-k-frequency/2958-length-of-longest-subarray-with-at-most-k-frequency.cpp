class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mpp;
        int i = 0, j = 0, n = nums.size(),maxx=0;
        while (j < n) {
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k && i<j) {
                mpp[nums[i]]--;
                i++;
            }
            maxx=max(maxx,j-i+1);
            j++;
        }
        return maxx;
    }
};