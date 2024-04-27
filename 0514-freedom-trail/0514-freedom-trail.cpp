class Solution {
    int helper(string ring,string key,int i,int j,int n){
        if(j==key.size())
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];

        int r=INT_MAX;
        for(int a=0;a<n;a++){
            if(ring[a]==key[j]){
                int ts= min(abs(a-i),n-abs(a-i))+1+helper(ring,key,a,j+1,n);
                r=min(r,ts);
            }
        }
        return t[i][j]=r;
    }
public:
    int t[101][101];
    int findRotateSteps(string ring, string key) {
        memset(t,-1,sizeof(t));
        int n=ring.size();
        return helper(ring,key,0,0,n);
    }
};