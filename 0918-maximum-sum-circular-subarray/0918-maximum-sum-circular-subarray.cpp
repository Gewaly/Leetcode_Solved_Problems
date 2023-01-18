class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    int currMaxSum = 0;
    int currMinSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;

    for (int &x : nums) {
      totalSum += x;
      currMaxSum = max(currMaxSum + x, x);
      currMinSum = min(currMinSum + x, x);
      maxSum = max(maxSum, currMaxSum);
      minSum = min(minSum, currMinSum);
    }

    return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
  }
    
};