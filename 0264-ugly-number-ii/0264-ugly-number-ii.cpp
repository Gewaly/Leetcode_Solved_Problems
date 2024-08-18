class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, vector<long long int>,greater<long long int>> pqm;
        pqm.push(1);
        n--;
        while(n--){
            long long int tp = pqm.top();
            while(!pqm.empty() && pqm.top()==tp){
                pqm.pop();
            }
            pqm.push(tp*2);
            pqm.push(tp*3);
            pqm.push(tp*5);
        }
        return pqm.top();
    }
};