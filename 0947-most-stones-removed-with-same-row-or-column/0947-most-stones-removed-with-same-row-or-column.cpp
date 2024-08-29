class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int getSize(int node) {
        return size[node];
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), maxRow = INT_MIN, maxCol = INT_MIN, sz, ncc = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        sz = maxRow + 1 + maxCol;
        DisjointSet ds(sz);
        for (auto it : stones) {
            int u = it[0];
            int v = maxRow + 1 + it[1];
            ds.unionBySize(u, v);
        }
        for (int i = 0; i < sz; i++) {
            if (ds.findParent(i) == i && ds.getSize(i) > 1)
                ncc++;
        }
        return n - ncc;
    }
};