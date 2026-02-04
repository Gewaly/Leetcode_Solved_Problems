const long long INF = -1e17;
const int N = 3;        
const bool start = true;
long long state[N];

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        for (int i = 0; i < N; i++) {
            state[i] = INF;
        }
        long long result = INF, prev = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            long long curr = nums[i];
            bool up = curr > prev, down = curr < prev;
            bool pattern = (N & 1) == start;
            for (int j = N - 1; j >= 0; j--) {
                bool valid = (pattern && up) || (!pattern && down);
                long long prevstate = j ? state[j - 1] : prev;
                state[j] = valid ? max(prevstate, state[j]) + curr : INF;
                pattern = !pattern;
            }
            result = max(result, state[N - 1]);
            prev = curr;
        }
        return result;
    }
};