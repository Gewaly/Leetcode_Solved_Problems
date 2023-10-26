class Solution {
public:
#define ll long long
#define mod 1000000007

int numFactoredBinaryTrees(vector<int>& arr) {
    
    unordered_map<ll,ll> mp;
    
    ll res=0;
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<arr.size();i++){
        
        ll curr = 1;
        
        for(int j=0;j<i;j++){
            
            if((arr[i]%arr[j])>0){
                continue;
            }
            
            ll n1 = arr[j], n2 = arr[i]/arr[j];
            
            curr = (curr + (mp[n1]*mp[n2])%mod)%mod;
        }
        
        mp[arr[i]] = curr;
        
        res = (res+curr)%mod;
    }
        
    return (int)res;
}
};