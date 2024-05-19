class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        bool odd = false;
        int min_diff = INT_MAX;
        for(int num: nums) {
            int flip = num^k;
            if(flip>num) {
                odd = !odd;
                sum += (num^k);
                min_diff = min(min_diff, flip-num);
            } else {
                sum+=num;
                min_diff = min(min_diff, num-flip);
            }
        }
        if(!odd) return sum;
        else return sum-min_diff;
    }
};