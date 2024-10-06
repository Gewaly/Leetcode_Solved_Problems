class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        deque<string> a, b;
        string temp = "";
        string c1, c2;
        stringstream iss1(s1), iss2(s2);
        while(iss1 >> c1) {
            a.push_back(c1);
        }
        while(iss2 >> c2) {
            b.push_back(c2);
        }
        while(!a.empty() && !b.empty() && a.front() == b.front()) {
            a.pop_front();
            b.pop_front();
        }
        while(!a.empty() && !b.empty() && a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        }
        return a.empty() || b.empty();
    }
};