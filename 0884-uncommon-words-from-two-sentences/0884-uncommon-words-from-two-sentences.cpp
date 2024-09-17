class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>arr;
        map<string, int>mp;
        string s3=s1+" "+s2;
          istringstream stream(s3);
          string word;
           while (stream >> word) {
               mp[word]++;
             }
        for (auto& x : mp) {
            if(x.second==1){
                arr.push_back(x.first);
            }
        }
            return arr;
            
        
        
    }
};