class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count =0;

        int n= nums.size();

        while(!is_sorted(nums.begin(),nums.end())){
            int mini = 1e9;
            int index = 0;
            count++;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mini){
                    mini =nums[i]+nums[i+1];
                    index =i;
                }
            }

            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                if(index!=i){
                    ans.push_back(nums[i]);
                }else{
                    ans.push_back(mini);
                    i++;
                }
            }

            nums =ans;
        }
        return count;
    }
};