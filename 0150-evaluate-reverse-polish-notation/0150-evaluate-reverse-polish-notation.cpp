class Solution {
public:
    long long int evalRPN(vector<string>& tokens) {
        stack<long long int>s;
        for(string x: tokens ){
            if(x=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(x=="-"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b-a);
            }
            else if(x=="*"){
               long long int a=s.top();
                s.pop();
                long long int b=s.top();
                s.pop();
                long long int j=a*b;
                s.push(j);
            }
            else if(x=="/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b/a);
            }
            else s.push(stoi(x));
           
        }
        return s.top();
        
    }
};