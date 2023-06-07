class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a!=0 || (b!=0 || c!=0)){
            int aa = a%2, bb = b%2, cc = c%2;
            a = a/2; b = b/2; c = c/2;
            
            if((aa|bb) != cc){
                if(cc == 1){
                    ans += 1;
                }else{
                    if(aa == 1) ans += 1;
                    if(bb == 1) ans += 1;
                }
            }
        }
        return ans;
    }
};