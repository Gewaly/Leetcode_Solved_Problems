class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
      for(int i=0;i<word.size();i++){
          if(isupper(word[i])) 
              cnt++;
      }
        if(cnt==word.size()) return true;
        else if(cnt==0) return true;
        else if(cnt==1&&isupper(word[0])) return true;
                else return false;
    }
};