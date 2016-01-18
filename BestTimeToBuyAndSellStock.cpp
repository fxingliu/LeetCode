class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) 
            return 0;
        int profit = 0, p_min = prices[0];
        for (int i=1; i<prices.size(); i++) {
            profit = max(profit, prices[i]-p_min);
            p_min = min(p_min, prices[i]);
        }
        return profit;
    }
};
