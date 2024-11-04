class Solution {
public:
    string compressedString(string word) {
       string res = "";
        int i = 0;
        
        while (i < word.size()) {
            char currentChar = word[i];
            int count = 0;

            while (i < word.size() && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }

            res += to_string(count) + currentChar;
      
            while (i < word.size() && word[i] == currentChar) {
                count = 0;
                while (i < word.size() && word[i] == currentChar && count < 9) {
                    count++;
                    i++;
                }
                res += to_string(count) + currentChar;
            }
        }

        return res;
    
        
    }
};