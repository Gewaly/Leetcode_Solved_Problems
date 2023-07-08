class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>arr;
        for(int i=1;i<weights.size();i++) 
        {
            long long sum=weights[i]+weights[i-1];
            arr.push_back(sum);
        }
        sort(arr.begin(),arr.end());
        long long mn=0,mx=0;
        int n = arr.size();
        for(int i=0;i<k-1;i++) mn+=arr[i];
        for(int i=n-1;i>=n-k+1;i--) mx+=arr[i];
        return mx-mn;
        
    }
};