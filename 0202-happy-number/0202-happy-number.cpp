class Solution {
public:
    bool isHappy(int n) {
        set <int> set1 ;
        while ( n != 1 && !set1.count (n) ) {
            set1.insert(n) ;
            n = next (n) ;
        }
        return n == 1 ;
    }
    int next ( int n ) {
        int sum = 0 ;
        while (n) {
            sum += pow ( (n % 10) , 2 ) ;
            n /= 10 ;
        }
        return sum ;
    }
};