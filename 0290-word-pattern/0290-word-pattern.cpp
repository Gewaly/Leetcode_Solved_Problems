class Solution {
public:
   bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_map<string, char> r;
        istringstream ss(str);
        string word;
        for (char c : pattern) {
            if (!(ss >> word)) return false;
            if ((m.count(c) && m[c] != word) || r.count(word) && r[word] != c) 
                return false;
            m[c] = word;
            r[word] = c;
        }
        return ss.eof();
   }
};