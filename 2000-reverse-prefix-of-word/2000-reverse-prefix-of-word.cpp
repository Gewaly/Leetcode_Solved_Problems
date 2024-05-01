class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j=0;
        for(int i=0;i<word.size();i++){
        if(word[i]==ch){j=i; break;}           
            }
        reverse(word.begin(),word.begin()+j+1);
        return word;
        
    }
};