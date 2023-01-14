class Solution {
public:
    string interpret(string command) {
        string s=command;
        string res="";
        for(int i=0;i<command.size();i++){
            if(s[i]=='G') res+='G';
            else if(s[i]=='(' && s[i+1]==')'){ 
                res+='o'; i++;
            }
            else if(s[i]=='(' && s[i+1]=='a' &&s[i+2]=='l'&&s[i+3]==')')
            {
                res+="al"; i+=3;
            }
        }
        return res;
        
    }
};