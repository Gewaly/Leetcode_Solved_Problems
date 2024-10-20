class Solution {
public:
    bool parseBoolExpr(string expr) {
        int n = expr.size();
        stack<char> st;
        for(int i = 0;i<n;++i){
            if(expr[i] != ')'){
                st.push(expr[i]);
            }
            else{
                int f=0,t=0;
                while(st.top() != '('){
                    if(st.top() == 'f') f++;
                    else if(st.top() =='t') t++;
                    st.pop();
                }
                st.pop();
                if(st.top() == '&'){
                    st.pop();
                    if(f>0){
                        st.push('f');
                    }
                    else{
                        st.push('t');
                    }
                }
                else if(st.top() == '|'){
                    st.pop();
                    if(t>0){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
                else{
                    st.pop();
                    if(f == 1){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
            }
        }
        if(st.top() == 'f'){
            return false;
        }
        return true;
    }
};