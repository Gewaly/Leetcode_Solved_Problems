class Solution {
public:
    unordered_map<string, bool> memo;
    bool f(int level, int i, string bottom, string curr, map<string, string> &mappa){
        if(bottom.size() == 1){
            return true;
        }
        if(i == bottom.size()-1){
            if(memo.count(curr))
                return memo[curr];
            bool res = f(level+1, 0, curr, "", mappa);
            return memo[curr] = res;
        }
        string base = {bottom[i], bottom[i+1]};
        for(char c: mappa[base]){
            bool res = f(level, i+1, bottom, curr + c, mappa);
            if(res) return true;
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, string> mappa;
        for(string &a: allowed){
            mappa[{a[0], a[1]}].push_back(a[2]);
        }
        return f(1, 0, bottom, "", mappa);
    }
};