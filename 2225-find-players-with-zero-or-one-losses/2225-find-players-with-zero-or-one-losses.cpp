class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> players;
        unordered_map<int, int> loseCount;
        for (auto& match : matches) {
            players.insert(match[0]);
            players.insert(match[1]);
            loseCount[match[1]]++;
        }

        vector<vector<int>> answer(2);
        for (auto& player : players) {
            if (loseCount[player] <= 1) {
                answer[loseCount[player]].push_back(player);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};