import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[1] - b[1]);

        int n = events.length;
        int[] endT = new int[n];
        int[] best = new int[n];

        for (int i = 0; i < n; i++) {
            endT[i] = events[i][1];
            best[i] = events[i][2];
            if (i > 0) best[i] = Math.max(best[i], best[i - 1]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int st = events[i][0];
            int val = events[i][2];

            int l = 0, r = n - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) >>> 1;
                if (endT[mid] < st) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx != -1) ans = Math.max(ans, val + best[idx]);
            ans = Math.max(ans, val);
        }

        return ans;
    }
}