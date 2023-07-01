class Solution {
public:
    void backtrack(int index, int end,int k, vector<int> &child,vector<int> &cookies, int &ans){
        if(index==end){
            int sum=0;
            for(int i=0;i<k;i++) {
                sum=max(sum,child[i]);
            }
            ans=min(ans,sum); 
            return;
        }
        for(int i=0;i<k;i++){
            child[i]+=cookies[index];
            backtrack(index+1,end,k,child,cookies,ans);
            child[i]-=cookies[index]; //backtrack
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k);
        int ans=1e9; 
        backtrack(0,cookies.size(),k,child,cookies,ans);
        return ans;
    }
};
