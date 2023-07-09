class Solution {
public:
    int largestVariance(string s) {
        vector<int>freq(26,0);
        int ans=0;
        for(int i=0;i<s.size();i++)freq[s[i]-'a']++;
        
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 || !freq[ch1-'a'] || !freq[ch2-'a'])continue;

                for(int i =1;i<=2;i++){
                    int ct1=0,ct2=0;
                    for(auto c:s){
                        ct1+= c==ch1;
                        ct2+= c==ch2;

                        if(ct1<ct2)ct1=ct2=0;

                        if(ct1>0 && ct2>0)ans=max(ans,ct1-ct2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        
      return ans;
    }
};