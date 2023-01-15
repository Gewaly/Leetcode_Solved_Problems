class Solution {
public:
    string toLowerCase(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            res+=tolower(s[i]);
        }
        return res;
    }
};