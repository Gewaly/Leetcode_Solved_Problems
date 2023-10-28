class Solution {
public:
    int countVowelPermutation(int n) {
        long ans=0, M=1e9+7;
        vector<long> curr(5, 1), prev(5, 0);
        vector<vector<int>> help = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<5 ; j++){
                for(int &x : help[j]){
                    prev[j] = (prev[j] + curr[x])%M;
                }
            }
            curr=prev;
            prev={0, 0, 0, 0, 0};
        }
        for(long &x : curr){
            ans=(ans+x)%M;
        }
        return ans;
    }
};