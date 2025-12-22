class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int m = s.size(),n = s[0].length();

        vector<int> res(n,1);

        for(int i =1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++ ){
                bool b = 0;
                for(int k = 0 ; k < m ;k ++ ){
                    if(s[k][j]>s[k][i]){
                        b = 1;
                        break;
                    }
                }
                if(!b){
                    res[i]=max(res[i],res[j]+1);
                }
            }
        }
        int me = 0;
        for(int i:res)me = max(me,i);
        return n-me;
    }
};