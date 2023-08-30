class Solution {
public:
    long long minimumReplacement(vector<int>& v) {
        long long ans = 0;
        long long Maxmin = v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]>Maxmin){
                int partition = ceil(v[i]/double(Maxmin));
                ans += partition - 1;
                Maxmin = v[i]/partition;
            }
            else Maxmin = v[i];
        }
        return ans;
    }
};