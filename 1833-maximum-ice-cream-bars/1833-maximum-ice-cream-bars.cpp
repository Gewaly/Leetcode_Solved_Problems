class Solution {
public:
    int maxIceCream(vector<int>& costs, long long coins) {
        vector<long long>arr(costs.size());
        sort(costs.begin(),costs.end());
        
        for(long long i=0;i<costs.size();i++){
            if(i==0) arr[i]=costs[i];
            else arr[i]=arr[i-1]+costs[i];
        }
       
      
        return  upper_bound(arr.begin(),arr.end(),coins)-arr.begin();;
    }
};