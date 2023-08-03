class Solution {
public:
    void solve(int cnt, string ds, string digits, map<char,string> &hsh, vector<string> &ans){
        if(cnt == digits.size()){
            ans.push_back(ds);
            return;
        }
        string str = hsh[digits[cnt]];
        for(int i = 0; i < str.length(); i++){
            ds += str[i];
            solve(cnt + 1, ds, digits, hsh, ans);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> hsh;
        hsh['2'] = "abc";
        hsh['3'] = "def";
        hsh['4'] = "ghi";
        hsh['5'] = "jkl";
        hsh['6'] = "mno";
        hsh['7'] = "pqrs";
        hsh['8'] = "tuv";
        hsh['9'] = "wxyz";
        int cnt = 0;
        string ds = "";
        if(digits.size() == 0) return ans;
        solve(cnt, ds, digits, hsh, ans);
        
          return ans; 
    }
};