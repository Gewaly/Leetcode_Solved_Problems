class Solution {
public:
    int minAddToMakeValid(string s) {
        int maxi = 0;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ')' && st.empty()){
                maxi++;
            }
            else if(s[i] == ')' && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
        return st.size()+maxi;
    }
};
