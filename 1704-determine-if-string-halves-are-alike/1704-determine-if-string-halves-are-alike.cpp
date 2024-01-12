class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0;
        for(int i=0;i<s.size()/2;i++){
            if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' ||
              s[i]=='O' || s[i]=='U') cnt1++;
            
        }
        int cnt2=0;
        for(int i=s.size()/2;i<s.size();i++){
               if(  s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' ||
              s[i]=='O' || s[i]=='U') cnt2++;
        }
        cout<<cnt1<<" "<<cnt2<<endl;
        return cnt1==cnt2;
        
    }
};