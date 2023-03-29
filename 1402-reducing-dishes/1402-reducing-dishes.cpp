class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        int sum = satisfaction[n-1];
        int val = satisfaction[n-1];
        int max = val;
        
        for(int i = n-2; i>=0; i--)
        {
            sum += satisfaction[i];
            val += sum;         // this sum is new sum since we have added current element in prev line

            if(val > max)
                max = val;
        }
        return max < 0 ? 0 : max;   // if max less than zero, then no point in makng dishes
    }
};