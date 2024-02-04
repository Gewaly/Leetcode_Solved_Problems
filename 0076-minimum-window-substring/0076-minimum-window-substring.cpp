class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int>m;
       for(auto x:t) m[x]++;
       int low=0, counter=0, min_length=INT_MAX,start=0;
       for(int i=0;i<s.size();i++){
           if(m[s[i]]>0) counter++;
           m[s[i]]--;
           if(counter==t.size()){
               while(low<i && m[s[low]]<0){
                   m[s[low++]]++;
               }
               if(min_length>i-low+1){
                   min_length=i-low+1;
                   start=low;
               }
           }
       }
       return min_length==INT_MAX ? "": s.substr(start,min_length);
    }
};