class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;
        
        for(auto &ch : s) mp[ch] += 1;

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for(auto itr = mp.begin() ; itr != mp.end() ; itr++){
            pq.push({itr->second, itr->first});
        }

        int size = s.size();
        int ind = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int freq        = top.first;
            char character  = top.second;
            if( 2 * freq - 1 > size ) return "";
            while(freq --> 0){
                if(ind >= size) ind = 1;
                s[ind] = character;
                ind += 2;
            }
        }

        return s;

    }
};