class Solution {
public:
   // vector<string>allSub;
    int ans=0;
   void isPalindrome(string S)
{
   
    string P = S;
 
    reverse(P.begin(), P.end());
 
    if (S == P) {
        ans++;
    }
}
  void printAllSubstrings(string s, int n) 
{
   
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            //allSub.push_back(temp);
            isPalindrome(temp);
            
        }
    }
}
    
    
    
    int countSubstrings(string s) {
     	int len = s.size();
        printAllSubstrings(s, len);
        //for(int i=0;i<allSub.size();i++){
     //       isPalindrome(allSub[i]);
     //   }
        return ans;
        

    }
};