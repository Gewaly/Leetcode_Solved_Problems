class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto i : s) { 
            mp[i]++;
        }
        multimap<int, char> mm;
        for(auto i : mp) { 
            mm.insert({i.second, i.first}); 
        }
        string str = "";
        for(auto i = mm.rbegin(); i != mm.rend(); i++) {
            str += string(i->first, i->second);
        }
        return str;
    }
};