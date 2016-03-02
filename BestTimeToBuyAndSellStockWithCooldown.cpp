class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // dp equation:
        // buy[i] = max(buy[i-1], sell[i-2]-prices[i])
        // sell[i] = max(sell[i-1], buy[i-1]+prices[i])
        int buy = -prices[0], sell = 0, prev_sell = 0, prev_buy;
        for (int i=1; i<prices.size(); i++) {
            prev_buy = buy;
            buy = max(buy, prev_sell-prices[i]);
            prev_sell = sell;
            sell = max(sell, prev_buy+prices[i]);
        }
        return max(prev_sell, sell);
    }
};
