class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        int diff=2*(numRows-1);
        for(int i=0;i<numRows;i++){
            int j=i;
            int d=diff-2*i;
            while(j<s.length()){
                ans+=s[j];
                if(i>0 && i<numRows-1 && j+d<s.length() ){
                    ans+=s[j+d];
                }
                j+=diff;
            }
        }
        return ans;
    }
};