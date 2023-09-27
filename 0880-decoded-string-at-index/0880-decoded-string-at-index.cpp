class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])) n*=s[i]-'0';
            else n++;
        }
        for(int i=s.length()-1;i>=0;i--){
            k=k%n;
            if(!k && isalpha(s[i])) return string(1,s[i]);
            if(isdigit(s[i])) n/=(s[i]-'0');
            else n--;
        }
        return "";
    }
};