class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
       for(int i=low;i<=high;i++){
           if(i%2!=0) cnt++;
       }
        return cnt;
        
    }
};