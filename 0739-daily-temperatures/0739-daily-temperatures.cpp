class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
 
        stack<int>s;
        vector<int>arr(temperatures.size(),0);
        for (int i=0;i<temperatures.size();i++) {
        while (!s.empty()&&temperatures[s.top()]<temperatures[i]) {
            arr[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
        return arr; 
        
    }
};