class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k==0) return nums;
        if (k>nums.size()) {
            return vector<int> (nums.size(),-1);
        }
        vector<long long int> pref(nums.size(),-1);
        pref[0]=nums[0];
        vector<int> avgs(nums.size(),-1);
        for (int i=1;i<nums.size();i++) {
            pref[i]=pref[i-1]+nums[i];
        }
        for (int i=k;i<nums.size()-k;i++) {
            if (i!=k) avgs[i]=(pref[i+k]-pref[i-k-1])/(2*k+1);
            else avgs[i]=(pref[i+k]/(2*k+1));
        }
        return avgs;
    }
};