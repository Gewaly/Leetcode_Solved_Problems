class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>arr1(26,0);
            for(auto x: s1){
                arr1[x-'a']++;
            }
        int n1=s1.size(),n2=s2.size();
        for(int i=0;i<n2-n1+1;i++){
        vector<int>arr2(26,0);
        
            for(int j=i;j<i+n1;j++){
                 arr2[s2[j]-'a']++; 
            }
            if(arr1==arr2) return true;
        }
         
        return false;
    }
};