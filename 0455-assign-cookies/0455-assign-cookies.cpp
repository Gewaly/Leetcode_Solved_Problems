class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int c=0;
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            if(g[i]<=s[j]) c++, i--,j--;
            
            else if(g[i]>s[j]) i--;
            
        }
        return c;
    }
};