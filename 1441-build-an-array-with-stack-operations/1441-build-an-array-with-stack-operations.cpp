class Solution {
public:
   vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        vector<string> ops;
        for (const int& num : target) {
            while (stream < num) {
                ops.push_back("Push"), stream++;
                ops.push_back("Pop");
            }
            ops.push_back("Push"), stream++;
        }
        return ops;
    }
};