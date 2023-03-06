class Solution {
public:
   int findKthPositive(vector<int>& arr, int k) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        cout<<"mid: "<<mid<<endl;
        if (arr[mid] - mid > k) hi = mid;
        else lo = mid + 1;
        cout<<"hi: "<<hi<<endl;
        cout<<"lo: "<<lo<<endl;
        cout<<endl;
    }
    return lo + k;
        
    }
};