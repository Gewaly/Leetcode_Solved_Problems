class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          int curr = 0;
        int total= 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i ++){
            int remaining = gas[i] - cost[i];
            if (curr < 0){
                start = i;
                curr= remaining;
            }
            else{
                curr += remaining;
            }
            total += remaining;
        }
        if (total < 0)
            return -1;
        else
            return start;
    }
};