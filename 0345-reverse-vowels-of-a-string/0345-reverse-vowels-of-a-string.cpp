class Solution {
public:
    string reverseVowels(string s) {
        string vowel="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')      vowel+='a';
            else if (s[i]=='A' ) vowel+='A';
            else if (s[i]=='e' ) vowel+='e';
            else if (s[i]=='i' ) vowel+='i';
            else if (s[i]=='o' ) vowel+='o';
            else if (s[i]=='u' ) vowel+='u';
            else if (s[i]=='E' ) vowel+='E';
            else if (s[i]=='I' ) vowel+='I';
            else if (s[i]=='O' ) vowel+='O';
            else if (s[i]=='U' ) vowel+='U';
                
        }
          reverse(vowel.begin(),vowel.end());
        string ans="";
           int j=0;
                for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' ){    
                  ans+=vowel[j]; j++;
            }
                    else ans+=s[i];
                }
        return ans;

        
    }
};