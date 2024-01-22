class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> umap;
        vector<int> v1;
        for(int i:nums)
        {
            umap[i]++;

        }
        for(auto i:umap)
        {
            if(i.second==2)
            v1.push_back(i.first);

        }
        for(int i=1;i<=nums.size();i++)
        {
            auto it=find(nums.begin(),nums.end(),i);
            if(it==nums.end())
            v1.push_back(i);
            
        }
        
        return v1;
    }
};