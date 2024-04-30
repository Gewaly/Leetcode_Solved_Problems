class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        int bits = 0; 
        map<int,int> cnt;
        cnt[0] = 1; 
        for(char c: word){
            bits^=1<<(c-'a');
            ans+=cnt[bits]++;
            for(int i = 0; i<11; i++){
                ans+=cnt[bits^(1<<i)];
            }
        }
        return ans;
    }
};