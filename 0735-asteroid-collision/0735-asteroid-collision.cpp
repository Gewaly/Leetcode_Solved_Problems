class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> res;
        for (int i: asteroids) {
            if (i > 0) res.emplace_back(i);
            else {
                while (!res.empty() && res.back() > 0 && -i > res.back()) res.pop_back();
                if (res.empty() || res.back() < 0) res.emplace_back(i);
                else if (-i == res.back()) res.pop_back();
            }
        }
        return res;
    }
};