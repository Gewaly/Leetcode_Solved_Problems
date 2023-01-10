class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        string s11=s1,s22=s2;
        sort(s11.begin(),s11.end());
        sort(s22.begin(),s22.end());
        if(s11!=s22) return false;
        int cnt=0;
        if(s1.size()==2&& s1!=s2) return false; 
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) cnt++;
        }
                  if(cnt>2) return false;
                  return true;
        }

};