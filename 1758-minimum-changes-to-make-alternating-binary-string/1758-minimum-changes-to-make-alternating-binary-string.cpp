class Solution {
public:
    int minOperations(string s) {
        
        int zeroOnOdd  = 0,oneOnEven = 0,oneOnOdd=0,zeroOnEven = 0;
        for( int i = 0 ; i < s.length(); i++)
        {
            if( i % 2 == 0)
                if(s[i] == '0')oneOnEven += 1;
                else zeroOnEven += 1;
            
            else
            {
                if(s[i] == '0') oneOnOdd += 1;
                else  zeroOnOdd += 1;
            }
        }

        return min( zeroOnEven + oneOnOdd , oneOnEven + zeroOnOdd);
    }
};