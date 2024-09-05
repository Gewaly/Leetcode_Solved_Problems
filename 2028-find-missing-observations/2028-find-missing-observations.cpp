class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int mod=rolls.size()+n;
        long long sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
        int ans= (mod*mean)-sum;
       if (ans < n || ans > 6 * n) {
        return {}; 
    }
    
    vector<int> res(n, 1);
    ans -= n; 

    for (int i = n - 1; i >= 0 && ans > 0; --i) {
        int increment = min(5, ans); 
        res[i]+= increment;
        ans -= increment;
    }
    
    return res;
        
    }
};