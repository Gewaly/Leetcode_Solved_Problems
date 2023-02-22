class Solution {
public:
  bool count(vector<int>& weights, int days, int capacity){
        int sm=0, day=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+sm<=capacity)
                sm += weights[i];
            else{
                sm=0;
                sm += weights[i];
                day++;
            }
        }
        if(sm>0)
            day++;
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        int res=0;
        while(left<=right){
            int mid=(left+right)/2;
           
                if(count(weights, days, mid)){
                    res=mid;
                    right=mid-1;
                }
                else left=mid+1;
                
            }
        return res;
    }
};