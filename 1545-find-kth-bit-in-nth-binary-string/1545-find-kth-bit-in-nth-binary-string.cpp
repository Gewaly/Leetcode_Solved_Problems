class Solution {
public:

  string findInvert(string s){
    for(int i=0;i<s.size();i++){
        s[i]=='1'?s[i]='0':s[i]='1';
    }
    return s;

  }
    char findKthBit(int n, int k) {
        string s="0";
        while(s.size()<k){
            string temp=findInvert(s);
            reverse(temp.begin(),temp.end());
             s=s+"1"+temp;
        }
        cout<<s<<endl;
        return s[k-1];
        
    }
};