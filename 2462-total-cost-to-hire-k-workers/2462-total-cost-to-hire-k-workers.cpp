class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        int n = costs.size(), i=0,j=n;
        long long ans=0;
        if(2*candidates <= n){
            i=candidates-1;
            j=n-candidates;
        }
        else{
            i=n-1;
        }
        for(int x=0;x<=i;x++){
            pq1.push(costs[x]);
        }
        for(int x=j;x<n;x++){
            pq2.push(costs[x]);
        }
        while(k--){
            int top1 = INT_MAX, top2 = INT_MAX;
            if(!pq1.empty()){
                top1 = pq1.top();
            }
            if(!pq2.empty()){
                top2 = pq2.top();
            }
            if(top1 <= top2){
                ans += top1;
                pq1.pop();
                if(i+1<j){
                    i++;
                    pq1.push(costs[i]);
                }
            }
            else if(top1 > top2){
                ans += top2;
                pq2.pop();
                if(j-1>i){
                    j--;
                    pq2.push(costs[j]);
                }
            }
        }
        return ans;
    }
};