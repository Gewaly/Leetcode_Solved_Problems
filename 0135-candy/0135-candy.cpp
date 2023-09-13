class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        vector<int> candy(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
                for(auto x: candy) cout<<x<<" ";
   cout<<endl;
        for(int i = ratings.size() - 2; i > -1; i--) {
            if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
                    //   cout<<candy[i]<<" "<<candy[i + 1]<<" "<<endl;
                candy[i] = candy[i + 1] + 1;
         
            } 
        }
        for(auto x: candy) cout<<x<<" ";
        for(int i: candy) sum += i;
        return sum;
    }
};