class Solution {

    static int dp[][];

    static int helper(int i, int d, int arr[]){
        int n = arr.length;
        if(d==0 && i==n) return 0;
        if(d<=0 || i>=n) return Integer.MAX_VALUE;

        if(dp[i][d]!=-1) return dp[i][d];

        int currMax = arr[i];
        int ans = Integer.MAX_VALUE;

        for(int x=i; x<n; x++){
            currMax = Math.max(currMax,arr[x]);
            int a = helper(x+1,d-1,arr);
            if(a!=Integer.MAX_VALUE){
                ans = Math.min(ans,currMax+a);
            }
        }
        return dp[i][d] = ans;
    }


    public int minDifficulty(int[] arr, int d) {
        dp = new int[305][15];
        for(var a : dp) Arrays.fill(a,-1);

        int ans = helper(0,d,arr);
        if(ans == Integer.MAX_VALUE) return -1;
        else return ans;
    }
}