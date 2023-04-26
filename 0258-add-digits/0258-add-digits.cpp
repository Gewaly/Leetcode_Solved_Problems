class Solution {
public:
    int addDigits(int num) {
       int n=num;
        int rem=n;
        while(rem>9){
                   rem=0;
            while(n>0){
                int m=n%10;
            rem+=m;
            n/=10;
            }
            n=rem;
        }
        return rem;
        
    }
};