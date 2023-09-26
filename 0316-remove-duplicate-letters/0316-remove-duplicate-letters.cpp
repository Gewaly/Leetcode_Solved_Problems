class Solution {
public:
    string removeDuplicateLetters(string s) {
   stack<char> charStack;

    vector<int> count(26, 0); 

     vector<bool> inStack(26, false);
    
    for (char c : s) {
        count[c - 'a']++;  }

    for (char c : s) {
        count[c - 'a']--;
        
        if (inStack[c - 'a']) {
                continue; 
                          }
            
        while (!charStack.empty() && c < charStack.top() && count[charStack.top() - 'a'] > 0) {
                inStack[charStack.top() - 'a'] = false;
                charStack.pop();
            }
            
            charStack.push(c);
            inStack[c - 'a'] = true;
                      }
    
    string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }
    
    return result;
   }
};