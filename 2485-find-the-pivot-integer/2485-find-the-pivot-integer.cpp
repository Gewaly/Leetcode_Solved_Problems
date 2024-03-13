class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int j=1,res=0,ans;
        for(int i=n;i>=1;i--) {   
            res+=i;
           ans=n-j;
            cout<<res<<" " <<ans*(ans+1)/2<<endl;
            if(ans*(ans+1)/2==res+ans ) { return ans; } 
         j++;
            
        }
    return -1;
        
    }
};