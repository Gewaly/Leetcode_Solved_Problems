class Solution {
public:
    int maxSideLength(vector<vector<int>>&ma,int th){
        int i,j,n=ma.size(),m=ma[0].size();
        vector<vector<int>>v(n+1,vector<int>(m+1,0));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                v[i][j]=v[i][j-1]+ma[i-1][j-1]+v[i-1][j]-
                        v[i-1][j-1];
            }
        }
        int low=1,high=min(n,m),an=0;

        while(low<=high){
            int md=(high+low)/2;
            bool b=0;
            for(i=md;i<n+1;i++){
                for(j=md;j<m+1;j++){
                    if(v[i][j]-v[i][j-md]-v[i-md][j]+v[i-md][j-md]<=th){
                       low = md+1;
                       an=md;
                       b=1;
                       break;
                    }
                }
                if(b==1) break;
            }
            if(b==0)
               high=md-1;
        }
        return an;
    }
};
