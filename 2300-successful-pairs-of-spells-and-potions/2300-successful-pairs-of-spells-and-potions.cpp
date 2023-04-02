class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int maxSpell = 0;
        for(int i=0; i<spells.size(); ++i){  
            maxSpell = max(maxSpell, spells[i]);
        }
        vector<int> counts(maxSpell+1, 0);

        for(int i=0; i<potions.size(); ++i){ 
            auto index = (success+potions[i]-1)/potions[i];
            if(index<counts.size()) counts[index]++;
        }

        for(int i=1; i<counts.size(); ++i){ 
            counts[i] +=counts[i-1];
        }

        vector<int> result(spells.size(), 0);
        for(int i=0; i<spells.size(); ++i){ 
            result[i] = counts[spells[i]];
        }
        return result;
    }
};