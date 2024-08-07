class Solution {
public:
    string numberToWords(int n) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        if(n==0)
        return "Zero";
        vector<string>mp(20),m(10),mpp(6,"");
        mp[0]="";
        mp[1]="One";
        mp[2]="Two";
        mp[3]="Three";
        mp[4]="Four";
        mp[5]="Five";
        mp[6]="Six";
        mp[7]="Seven";
        mp[8]="Eight";
        mp[9]="Nine";
        mp[10]="Ten";
        mp[11]="Eleven";
        mp[12]="Twelve";
        mp[13]="Thirteen";
        mp[14]="Fourteen";
        mp[15]="Fifteen";
        mp[16]="Sixteen";
        mp[17]="Seventeen";
        mp[18]="Eighteen";
        mp[19]="Nineteen";
        m[2]="Twenty";
        m[3]="Thirty";
        m[4]="Forty";
        m[5]="Fifty";
        m[6]="Sixty";
        m[7]="Seventy";
        m[8]="Eighty";
        m[9]="Ninety";
        mpp[1]="Hundred";
        mpp[2]="";
        mpp[3]="Thousand";
        mpp[4]="Million";
        mpp[5]="Billion";
        vector<string>v;
        int j=2;
        string str="";
        while(n>0)
        {
            str="";
            int a=n%10;
            n/=10;
            int b=n%10;
            n/=10;
            int c=n%10;
            n/=10;
            if(c!=0)
            {
                str+=mp[c]+" "+mpp[1]+" ";
            }
            if(b!=0)
            {
                if(b==1)
                {
                    str+=mp[b*10+a]+" ";
                }
                else
                {
                    str+=m[b]+" ";
                    if(a!=0)
                    str+=mp[a]+" ";
                }
            }
            else if(a!=0)
            {
                str+=mp[a]+" ";
            }
            if(str!="")
            str+=mpp[j];
           
            if(j==2&&str!="")
            {
                str.pop_back();
            }
            j++;
            if(str!="")
            v.push_back(str);
        }
        j=v.size();
        str="";
        for(int i=j-1;i>=0;i--)
        {
            str+=v[i];
            if(i!=0)
            {
                str+=" ";
            }
        }
        return str;
    }
};