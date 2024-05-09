class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long n=happiness.size(),res=0;
        for(long long i=0;i<n;i++){
            if(k==0) return res;
            if((happiness[i]-i)<0) res=res+0;
            else res=res+(happiness[i]-i);
            k--;
        }
        return res;
        
    }
};