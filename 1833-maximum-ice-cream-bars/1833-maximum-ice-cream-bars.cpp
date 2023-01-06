class Solution {
public:
    int maxIceCream(vector<int>& costs,int coins) {
        vector<long long>pre(costs.size());
        
        sort(costs.begin(),costs.end());// sort costs--> {1,1,2,3,4} 
        // prefix sum
        for(int i=0;i<costs.size();i++){
            if(i==0) pre[i]=costs[i];
            else pre[i]=pre[i-1]+costs[i];
        }
        //pre={1,2,4,7,11}
       
        // return the index greater than coins 
        return  upper_bound(pre.begin(),pre.end(),coins)-pre.begin();;
    }
};