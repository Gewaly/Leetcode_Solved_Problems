class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int>days(101,0),ans(n,0);
        for(int i=n-1;i>=0;i--){
            int cur=temperatures[i];
            fill(days.begin(),days.begin()+cur,i);
            if(days[cur]!=0) ans[i]=days[cur]-i;
        }
        return ans; 

    }
};