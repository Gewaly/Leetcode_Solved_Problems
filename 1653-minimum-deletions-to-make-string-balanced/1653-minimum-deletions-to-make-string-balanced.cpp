class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0, counts = 0;
        for (char ch : s) {
            if (ch == 'b') {
                counts += 1;
            } else if (counts) {
                deletions += 1;
                counts -= 1;
            }
        }
        return deletions;
    }
};
