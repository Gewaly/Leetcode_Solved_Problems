class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long res=0;
        while(left!=right){
            left>>=1; right>>=1;
            res++;
         }
        return left<<res;
        
    }
};