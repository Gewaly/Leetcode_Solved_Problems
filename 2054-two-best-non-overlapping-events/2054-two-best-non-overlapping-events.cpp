class Solution {
private:
    int binSearch(int left, int right, int target, const vector<vector<int>>& events) {
        if (left >= right) {
            return right;
        }
        
        int mid = left + (right - left) / 2;
        if (events[mid][0] > target) {
            return binSearch(left, mid, target, events);
        } else {
            return binSearch(mid + 1, right, target, events);
        }
    }
    
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        
        int n = events.size();
        vector<int> maxSuffix(n);
        
        maxSuffix[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            maxSuffix[i] = max(maxSuffix[i + 1], events[i][2]);
        }
        
        int maxValue = 0;
        for (int i = 0; i < n; i++) {
            int currentValue = events[i][2];
            int nextEventIndex = binSearch(i + 1, n, events[i][1], events);
            int additionalValue = (nextEventIndex < n) ? maxSuffix[nextEventIndex] : 0;
            maxValue = max(maxValue, currentValue + additionalValue);
        }
        
        return maxValue;
    }
};