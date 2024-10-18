class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int orr = accumulate(begin(nums), end(nums), 0, [&](int a, int b) {
            return a | b;
        });

        int n = nums.size(), ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int cur = 0;
            for (int index = 0; index < n; index++) {
                if ((i >> index) & 1) {
                    cur |= nums[index];
                }
            }
            ans += (cur == orr);
        }

        return ans;
    }
};
