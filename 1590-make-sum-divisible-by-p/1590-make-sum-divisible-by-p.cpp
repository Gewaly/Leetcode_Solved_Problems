class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int tmp = 0, res = nums.size(), need_to_remove = 0;
        for (auto num : nums) need_to_remove = (need_to_remove + num) % p;
        if (need_to_remove == 0) return 0;
        
        unordered_map<int, int> pre_sum;
        pre_sum[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            tmp = (tmp + nums[i]) % p;
            pre_sum[tmp] = i;
            int rest = (tmp - need_to_remove + p) % p;
            
            if (pre_sum.find(rest) != pre_sum.end()) res = min(res, i - pre_sum[rest]);
        }
        return res >= nums.size() ? -1 : res;
    }
};