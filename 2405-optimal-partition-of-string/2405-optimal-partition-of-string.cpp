class Solution {
public:
    int partitionString(string s) {
        int cnt=1;
        string chars;
        chars+=s[0];
        for(int i=1; i<s.size();i++){
            if (chars.find(s[i]) != std::string::npos){ // found
              chars="";
            chars+=s[i];
            cnt++;
            }
             else{        // not found
                 chars+=s[i];
             } 
        }
    cout<<chars<<endl<<cnt;
     //   if(chars.size()==1) cnt++;
    return cnt;
        
    }
};