class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        for (const auto& sq : squares) {
            low = min(low, static_cast<double>(sq[1]));
            high = max(high, static_cast<double>(sq[1] + sq[2]));
        }
        
        double eps = 1e-5;
        while (high - low > eps) {
            double mid = (low + high) / 2;
            double upper = 0, lower = 0;
            
            for (const auto& sq : squares) {
                double y = sq[1], len = sq[2];
                double top = y + len;
                
                if (top <= mid) {
                    lower += len * len;
                } else if (y >= mid) {
                    upper += len * len;
                } else {
                    double below = mid - y;
                    double above = top - mid;
                    lower += below * len;
                    upper += above * len;
                }
            }
            
            (upper > lower) ? (low = mid) : (high = mid);
        }
        return low;
    }
};