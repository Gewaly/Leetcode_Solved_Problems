class Solution {
public:
    template<typename P>
    bool topoIter(int n, vector<vector<int>> out, P&& job) {
        vector<int> in(n);
        for(int i = 0; i < n; ++i) 
            for(const auto& j : out[i])
                ++in[j];
        queue<int> q{};
        for(int i = 0; i < n; ++i) if(in[i] == 0) q.push(i);
        while(!q.empty()) {
            auto now = q.front(); q.pop();
            job(now);
            --n;
            for(const int& nxt : out[now]) 
                if(--in[nxt] == 0)
                    q.push(nxt);
        }
        return n == 0;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(auto& id : group) if(id == -1) id = m++;
        
        
        vector<int> sz_grp(m,0);
        vector<vector<int>> beforeGroups(m);
        for(int i = 0; i < n; ++i) {
            ++sz_grp[group[i]];
            beforeGroups[group[i]].reserve(beforeItems[i].size()/4);
            for(const int& j : beforeItems[i])
                if(group[i] != group[j]) 
                    beforeGroups[group[i]].push_back(group[j]);
        }
        
        vector<int> idx = std::move(sz_grp);
        if(!topoIter(m, std::move(beforeGroups),
            [&,acc=0](const int& g) mutable { acc += exchange(idx[g], acc); })) {
            return {};
        }

        vector<int> ans(n);
        if(!topoIter(n, std::move(beforeItems),
            [&](const int& i) { ans[idx[group[i]]++] = i; })) {
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};