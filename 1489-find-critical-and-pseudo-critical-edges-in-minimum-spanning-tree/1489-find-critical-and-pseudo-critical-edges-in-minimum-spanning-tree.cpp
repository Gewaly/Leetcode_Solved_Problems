class Solution {
private:
    int parent[101];
    int rank[101];

    void dsu(int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int n){
        if(parent[n] == n)
            return n;
        
        return parent[n] = findParent(parent[n]);
    }

    void unionDSU(int a, int b){
        int para = findParent(a);
        int parb = findParent(b);
        if(para == parb)
            return;;
        
        int ranka = rank[para];
        int rankb = rank[parb];
        
        if(ranka > rankb)
            parent[parb] = para;
        else if(rankb > ranka)
            parent[para] = parb;
        else{
            parent[para] = parb;
            rank[parb]+=1;
        }
    }

public:
    int makeMST(vector<vector<int>>&edges, int index, int n){
        dsu(n);
        int res = 0;

        for(int i=0;i<edges.size();i++){
            if(i == index)
                continue;
            
            int para = findParent(edges[i][0]);
            int parb = findParent(edges[i][1]);
            if(para!=parb){
                res+=edges[i][2];
                unionDSU(edges[i][0], edges[i][1]);
            }
        }
        return res;
    }

    int makeMSTwithIndex(vector<vector<int>>&edges, int index, int n){
        dsu(n);
        int res = edges[index][2];

        unionDSU(edges[index][0], edges[index][1]);

        for(int i=0;i<edges.size();i++){
            int para = findParent(edges[i][0]);
            int parb = findParent(edges[i][1]);
            if(para!=parb){
                res+=edges[i][2];
                unionDSU(edges[i][0], edges[i][1]);
            }
        }
        return res;
    }

    void dfs(vector<pair<int, int>>adj[], int node, vector<int>&vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it.first] == 0)
                dfs(adj, it.first, vis);
        }
    }

    vector<vector<int>>criticalnpseudoCritical(vector<vector<int>>&edges, int n){
        int minWtMST = makeMST(edges, -1, n);

        vector<vector<int>>res;
        vector<int>critical;
        vector<int>pseudoCritical;

        for(int i=0;i<edges.size();i++){
            vector<pair<int, int>>adj[n];
            for(int j=0;j<edges.size();j++){
                if(i == j) continue;
                int a = edges[j][0];
                int b = edges[j][1];
                int wt = edges[j][2];

                adj[a].push_back({b, wt});
                adj[b].push_back({a, wt});
            }
            int compCount = 0;
            vector<int>vis(n, 0);

            for(int j=0;j<n;j++){
                if(!vis[j]){
                    ++compCount;
                    dfs(adj, j, vis);
                }
            }

            if(compCount > 1){
                critical.push_back(edges[i][3]);
                continue;
            }
            
            int val = makeMST(edges, i, n);
            int val2 = makeMSTwithIndex(edges, i, n);

            if(val > minWtMST){
                critical.push_back(edges[i][3]);
            }
            if(val == val2){
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        res.push_back(critical);
        res.push_back(pseudoCritical);

        return res;

    }

    static bool comp(vector<int>a, vector<int>b){
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), comp);
        return criticalnpseudoCritical(edges, n);
    }
};