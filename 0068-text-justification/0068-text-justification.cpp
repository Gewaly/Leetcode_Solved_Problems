class Solution {
public:
    string cal(string &str,int maxWidth)
    {
        int n = str.size();

        if(str[n-1]==' ')
            str.pop_back();

        if(str.size()==maxWidth)
            return str;

        vector<string> vec;
        int totalsz=0;
        string s="";

        for(auto x:str)
        {
            if(x==' ')
            {
                if(s.size())
                    vec.push_back(s);
                s="";
            }
            else
                s+=x;
        }

        if(s.size())
            vec.push_back(s);

        for(auto x:vec)
            totalsz+=x.size();

        int remaning_space = maxWidth-totalsz;
        string ans="";

        if(vec.size()==1)
        {
            ans+=vec[0];
            ans.append(remaning_space,' ');
            return ans;
        }

        int quotient=remaning_space/(vec.size()-1);
        int rem=remaning_space%(vec.size()-1);

        for(int i=0;i<vec.size();i++)
        {
            ans+=vec[i];
            if(i!=vec.size()-1)
            {
                if(rem>0)
                {
                    ans.append(quotient+1,' ');
                    rem--;
                }
                else
                    ans.append(quotient,' ');   
            }
        }
        return ans;        
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        string str="";
        for(auto x:words)
        {
            if(str.size() + x.size() + 1 < maxWidth)
                str+=x + " ";
            else
            {
                if(str.size() + x.size() <= maxWidth)
                {
                    str+=x;
                    vec.push_back(str);
                    str="";
                }
                else
                {
                    vec.push_back(str);
                    str=x+" ";
                }
            }
        }

        for(auto &x:vec)
            x = cal(x,maxWidth);

        if(str.size())
        {
            if(str[str.size()-1]==' ')
                str.pop_back();
            str.append(maxWidth-str.size(),' ');
            vec.push_back(str);
        }

        return vec;
    }
};