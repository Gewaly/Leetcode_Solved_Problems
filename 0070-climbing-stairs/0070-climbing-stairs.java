class Solution {
    public int climbStairs(int n) {
           int l=0,r=1,sum=0;
        for(int i=0;i<n;i++){
            sum=l+r;
            l=r;
            r=sum;
        }
        return sum; 
    }
}