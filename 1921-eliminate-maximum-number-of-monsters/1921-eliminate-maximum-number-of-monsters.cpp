class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> freqs(dist.size(), 0); 
		
        for (int i = 0; i < dist.size(); i++){
            int time = ceil((double)dist[i] / speed[i]);
            if (time < dist.size())
                freqs[time]++;
        }
		
        int monsters = freqs[0];
        for (int i = 1; i < freqs.size(); i++){
            monsters += freqs[i];
            if (monsters > i)
                return i;
        }
        return freqs.size();
    }
};