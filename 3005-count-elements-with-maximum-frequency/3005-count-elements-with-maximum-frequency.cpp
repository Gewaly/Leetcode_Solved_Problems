class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>arr;
        for(auto x: mp) arr.push_back(x.second);
        sort(arr.rbegin(),arr.rend());
    
        int res=0;
      for(int i=0;i<arr.size();i++){
          if(arr[i]==arr[0]) res+=arr[i];
          else break;
      }
        return res;
        
    }
};