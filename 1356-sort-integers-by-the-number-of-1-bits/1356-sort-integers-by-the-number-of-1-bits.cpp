class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(begin(arr), end(arr), []( int a, int b) {
       int x = bitset<32>(a).count();
       int y = bitset<32>(b).count();
      return x == y ? a < b : x < y;
    });
    return arr;
  }
};