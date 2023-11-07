class Solution {
public:
    string reverseWords(string s) {
     vector<string>ans;
        string st="";
        for(int i=0;i<s.size();i++){
                st="";
            while(s[i]!=' '){
                st+=s[i];
                i++;
                if(i==s.size()) break;
            }

            //cout<<st<<endl;
            if(!st.empty()) ans.push_back(st);
        }
        reverse(ans.begin(),ans.end());
        string res="";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
            if(i!=ans.size()-1) res+=" ";

        }
        return res;

    }
};