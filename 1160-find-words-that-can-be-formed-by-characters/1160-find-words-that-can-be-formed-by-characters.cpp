class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int>ch;
        for(int i=0;i<chars.length();i++){
            ch[chars[i]]++;
        }
        for(int i=0;i<words.size();i++){
            unordered_map<char,int>str;
            string s=words[i];
            for(int j=0;j<s.length();j++){
                str[s[j]]++;
            }
            bool flag=true;
            for(int k=0;k<s.length();k++){
                if(str[s[k]]>ch[s[k]]){
                    flag=false;
                    break;
                }
            }
            if(flag)
            ans+=s.length();
        }
        return ans;
    }
};