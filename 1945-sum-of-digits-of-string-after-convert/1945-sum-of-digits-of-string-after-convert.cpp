class Solution {
public:
    int getLucky(string s, int k) {
        int res=0;
        string ss=""; 
        
        for(int i=0;i<s.size();i++){
            int n= s[i]-'a'+1;
            ss+=  to_string(n);
        }
       while(k--){
           res=0;
        for(int i=0;i<ss.size();i++){
        res+=ss[i]-'0';
            
        }
       ss=to_string(res);
       }
        
        return res; 
        
        
        
        
    }
};