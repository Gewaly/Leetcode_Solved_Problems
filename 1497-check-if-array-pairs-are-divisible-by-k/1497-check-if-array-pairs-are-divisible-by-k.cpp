class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        
        for (int num : arr) {
            int rem = ((num % k) + k) % k; 
            res[rem]++;
        }
        if (res[0] % 2 != 0) {
            return false;
        }
        
        for (int i = 1; i < k; ++i) {
            if (res[i] != res[k - i]) {
                return false; 
            }
        }
        
        return true;
    }
};