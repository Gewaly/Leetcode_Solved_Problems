class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         long long start = 1, end = 100000000000000;
        while (start <= end) {
            long minTimeForTotalTrips = 0;
            long mid = start + (end - start) / 2;
            for (int t : time)
                minTimeForTotalTrips += mid / t;
            if (minTimeForTotalTrips >= totalTrips)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};