class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int res = 1, l = index, r = index;
        maxSum -= n;
        while (maxSum >= r - l + 1) {
            maxSum -= r - l + 1;
            res++;
            if (l > 0) {
                --l;
            }
            if (r < n - 1) {
                ++r;
            }
            if (r - l + 1 == n) {
                break;
            } 
        }
        res += maxSum / n;
        return res;
    }
};