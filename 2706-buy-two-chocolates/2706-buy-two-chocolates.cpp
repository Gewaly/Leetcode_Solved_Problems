class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int two_ch=prices[0]+prices[1];
        if(two_ch <= money ) return money-two_ch;
        return money;
        
    }
};