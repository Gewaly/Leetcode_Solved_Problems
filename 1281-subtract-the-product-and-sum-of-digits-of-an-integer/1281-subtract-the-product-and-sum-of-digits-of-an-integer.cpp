class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1,sum=0;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            sum+=s[i]-'0';
            prod=prod*(s[i]-'0');
        }
       int res=prod-sum;
        return res;
        
        
    }
};