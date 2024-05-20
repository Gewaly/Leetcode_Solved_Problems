class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>arr;
            for (int i = 0; i < (1 << nums.size()); i++) {
                vector<int>a;
                  for (int j = 0; j < nums.size(); j++) {
                                  if ((i & (1 << j)) != 0) {
                                  a.push_back(nums[j]);
                                  }
                  }
                    arr.push_back(a);

            }
        /*
                for(int i=0;i<arr.size();i++){
                                for(int j=0;j<arr[i].size();j++){
                                
                                cout<<arr[i][j]<<" ";
                                }
                cout<<endl;
                }

        */
        
        int res=0,ans=0;
        for(int i=0;i<arr.size();i++){
            res=0;
            for(int j=0;j<arr[i].size();j++){
                res^=arr[i][j];
            }
                            cout<<res<<" ";

            cout<<endl;
            ans+=res;
        }


       return ans; 
    }
};