class Solution {
public:
    vector<int>ans; 
    int frq[26] = {0}; 
    vector<vector<int>>v; 
    string x;

    void Dfs (int st,int pr){
       
       int pre = frq[x[st] - 'a'];
   
       for(auto ch:v[st])
            if(pr != ch)
                Dfs(ch,st);
        
        frq[x[st]-'a']++; 
        ans[st] = frq[x[st]-'a'] - pre; 
    }
  
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n),v.resize(n);
            x = labels;
        for(auto it:edges)
            v[it[0]].push_back(it[1]),v[it[1]].push_back(it[0]);

        Dfs(0,-1);
      
        return ans;
    }
};