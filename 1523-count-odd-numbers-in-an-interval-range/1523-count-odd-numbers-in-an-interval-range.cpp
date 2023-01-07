class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
        if(low%2!=0){
        for(int i=low;i<=high;i+=2){
            cnt+=1;
        }}
        else {
            for(int i=low+1;i<=high;i+=2){
            cnt+=1;
        }}
        return cnt;
        
    }
};