class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x=INT_MAX;
        int y = INT_MAX;
        for(auto a:nums){
            if(a<=x){
                x=a;
            }
            else if(a<=y){
                y=a;
            }
            else{
                return true;
            }
           // cout<<"x: "<<x<<" "<<"y: "<<y<<endl;

        }
        return false;
    }
};