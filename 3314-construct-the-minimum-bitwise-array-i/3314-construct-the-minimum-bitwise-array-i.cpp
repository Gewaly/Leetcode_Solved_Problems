class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            int count = 0, num = nums[i];
            while (nums[i]) {
                if ((1 & nums[i]) == 1)
                    count++;
                else 
                    break;
                nums[i] >>= 1;
            }
            if (num % 2 == 1)
                res[i] = num - pow(2, count - 1);
        }
        return res;
    }
};