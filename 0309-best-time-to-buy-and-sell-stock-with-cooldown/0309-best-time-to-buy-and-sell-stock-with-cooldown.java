class Solution {
    public int maxProfit(int[] prices) {
         int n = prices.length;
        if(n<=1)
            return 0;
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0; 
        for(int i=1;i<n;i++)
        {
            int pre_buy = buy, pre_sell = sell;
            int pre_cooldown = cooldown;
            buy = Math.max(pre_buy, pre_cooldown-prices[i]);
            sell = Math.max(pre_sell, prices[i]+pre_buy);
            cooldown = Math.max(pre_cooldown,pre_sell);
        }
        return Math.max(sell,cooldown);
        
    }
}