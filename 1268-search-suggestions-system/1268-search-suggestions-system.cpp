class Trie{
    struct Node{
        bool isWord = false;
        vector<Node*> children{vector<Node*>(26,NULL)};
    } *Root, *curr;


    void dfs(Node *curr, string &word, vector<string> &ans){
        if(ans.size()==3)return;
        if(curr->isWord)ans.push_back(word);

        for(char c='a';c<='z';c++){
            if(curr->children[c-'a']){
                word+=c;
                dfs(curr->children[c-'a'],word,ans);
                word.pop_back();
            }
        }
    }

public:
    Trie(){
        Root = new Node;
    }

    void insert(string &s){
        curr=Root;
        for(char &c :s){
            if(!curr->children[c-'a'])curr->children[c-'a']=new Node();
            curr=curr->children[c-'a'];
        }
        curr->isWord=true;
    }

    vector<string> getwords(string &prefix){
        curr=Root;
        vector<string> res;

        for(char &c: prefix){
            if(!curr->children[c-'a'])return res;
            curr=curr->children[c-'a'];
        }
        dfs(curr,prefix,res);
        return res;
    }
};   


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        vector<vector<string>> res;
        for(string &w:products)trie.insert(w);
        string prefix;
        for(char &c:searchWord){
            prefix+=c;
            res.push_back(trie.getwords(prefix));
        }   
        return res;
    }
};