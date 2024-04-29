class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorResult = k;
        for (int num : nums) {
            xorResult ^= num;
        }
        int count = 0;
        while (xorResult > 0) {
            count += xorResult & 1;
            xorResult >>= 1;
        }

        return count;
    }
};