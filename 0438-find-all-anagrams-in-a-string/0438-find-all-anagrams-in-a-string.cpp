class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;
        vector<int>arr1(26,0);
        for(auto x: p){
            arr1[x-'a']++;
        }
        int pp=p.size(),ss=s.size();
        for(int i=0;i<ss-pp+1;i++){
             vector<int>arr2(26,0);
        
            for(int j=i;j<i+pp;j++){
                 arr2[s[j]-'a']++; 
            }
            if(arr1==arr2) res.push_back(i);
        }
        return res;
    }
};