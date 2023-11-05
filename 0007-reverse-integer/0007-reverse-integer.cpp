class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        while(x!=0){
            ans=ans*10+x%10;
            cout<<ans<<endl;
            x/=10;
            if(abs(ans)>INT_MAX) return 0;
            
        }
        return ans;
        
    }
};