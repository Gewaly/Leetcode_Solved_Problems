class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& M, int K) {
        int y = M.size(), x = M[0].size();
        vector<int> ans(K);
        priority_queue<int> heap;
        for (int i = 0; i < y; i++) {
            heap.push((find(M[i]) << 7) + i);
            if (heap.size() > K) heap.pop();
        }
        while (heap.size()) {
            ans[heap.size()-1] = heap.top() & (1 << 7) - 1;
            heap.pop();
        }
        return ans;
    }
    int find(vector<int> row) {
        int x = row.size();
        int left = 0, right = x;
        while (left <= right) {
            int mid = left + right >> 1;
            if (mid < x && row[mid] > 0) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};