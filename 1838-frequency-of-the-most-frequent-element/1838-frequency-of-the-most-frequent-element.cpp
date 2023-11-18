class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) 
    {
        sort(nums.begin(),nums.end());
        long window_sum = 0,window_size = 0,result = 0,pos = 0;
        for(int i = 0;i<nums.size();i++)
        {
            window_sum+=nums[i];  window_size = i-pos+1;
            while(( nums[i]*window_size - window_sum ) > k)  window_sum-=nums[pos++], window_size--;
            
            result = max(result,window_size);
        }
        return result;   
    }

};