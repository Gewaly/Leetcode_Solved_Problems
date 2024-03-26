class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        vector<int>res(s.begin(),s.end());
        int f=0;
        for(int i=0;i<res.size();i++){
            if(res[i]==1){
                f=1;
                for(int j=1;j<res.size()+1;j++){                    
                    if(j!=res[i]) return j;
                     i++;
                    if(i==res.size()) goto w;
                }
            }
        }
        w:;
            return ((f==1)?(res[res.size()-1])+1:1);
        
    }
};