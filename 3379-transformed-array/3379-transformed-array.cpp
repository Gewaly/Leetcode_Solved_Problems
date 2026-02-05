class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);
        for(int i = 0 ; i < n ; i++)
        {
            results[i] = nums[((i + nums[i] + n)%n + n)%n];
        }
        return results;
    }
};