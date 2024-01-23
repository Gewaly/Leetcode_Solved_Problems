class Solution {
public:
    int ans=0;

    bool isValid(string s){
        int n=s.size();
        if(n>26) return false;
        int freq[26]={0};
        for(int i=0;i<n;i++) freq[s[i]-'a']++;
        for(int i=0;i<26;i++) if(freq[i]>=2) return false;

    return true;
    }

    void maxlength(vector<string> &arr, int i, string s){
        if(s.size()>ans) ans=s.size();
        int n=arr.size();
        if(i==n-1) return;
        for(int j=i+1;j<n;j++) if(isValid(s+arr[j])) maxlength(arr,j,s+arr[j]);
    }

    int maxLength(vector<string>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++) if(isValid(arr[i])) maxlength(arr,i,arr[i]);

    return ans;
    }
};