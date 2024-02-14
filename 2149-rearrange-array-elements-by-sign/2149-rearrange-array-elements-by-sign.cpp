class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int i = 0, j = 1;
        for (auto& num : nums) {
            if (num > 0) result[i] = num, i += 2;
            else result[j] = num, j += 2;
        }
        return result;
    }
};