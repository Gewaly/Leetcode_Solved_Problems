class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string>arr;
       for(int i=0;i<strs[0].size();i++){
           string ss;
           for(int j=0;j<strs.size();j++){
               ss+=strs[j][i];
       }
        arr.push_back(ss);
             }
             int cnt=0;
             for(auto x:arr){
                if(!is_sorted(x.begin(),x.end())){
                    cnt++;
                }
             }
          return cnt;
    }
};