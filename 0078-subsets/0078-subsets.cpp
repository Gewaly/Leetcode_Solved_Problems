class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        return arr;
        
    }
};