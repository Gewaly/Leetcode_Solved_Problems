class Solution {
public:
    
     class UnionFind{
        int numComponents;
        vector<int> rank;
        vector<int> parent;
        public:
        UnionFind(int n){
            numComponents = n;
            rank = vector<int>(n, 0);
            parent = vector<int>(n);
            for(int i = 0; i<n; i++) parent[i] = i;
        }
        
        int components(){return numComponents;}
        
        int find(int p){
            while(p != parent[p]){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }
        
        void unionn(int p, int q){
            int rootp = find(p); int rootq = find(q);
            if(rootp == rootq) return;
            if(rank[rootp] < rank[rootq]) parent[rootp] = rootq;
            else{
                parent[rootq] = rootp;
                if(rank[rootp] == rank[rootq]){rank[rootp]++;}
            }
            numComponents--;
        } 
    };
    
int spf[100005];
    
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i <= 100000; i++)
        spf[i] = i;
    for (int i = 4; i <=100000; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i <= 100000; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= 100000; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
    
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size()==1) return true;
        for(auto i:nums){
            if(i==1) return false;
        }
        sieve();
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            set<int> st; 
            while(x!=1){
               st.insert(spf[x]); x=x/spf[x];
            }
            for(auto num:st){
                mp[num].push_back(i);
            }
        }
        int n=nums.size();
        UnionFind uf(n);
        for(auto p:mp){
            auto v=p.second;
            if(v.size()==1) continue;
            int sz=v.size();
            int u=v[0];
            for(int i=1;i<sz;i++){
                uf.unionn(u,v[i]);
            }
        }
        
        if(uf.components()==1) return true;
        return false;
    }
};