class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if (n<2 || k<1) return 0;
        if (k >= n/2) return quickSolve(prices);
        
        // balance - the balance with at most j transactions with item 0 to i
        // profit - the profit with at most j transactions with item 0 to i
        vector<int> balance(n+1, INT_MIN), profit(n+1, 0);
        
        for (int i=0; i<n; ++i) {
            for (int j=1; j<=k; ++j) {
                balance[j] = max(balance[j], profit[j-1] - prices[i]); // whether to buy at prices[i]
                profit[j] = max(profit[j], balance[j] + prices[i]); // whether to sell at prices[i]
            }
        }
        
        return profit[k];
    }
    
private:
    // efficient in frequent trades
    // same as BestTimeToBuyStockII
    int quickSolve(vector<int>& v) {
        int profit = 0;
        for (int i=1; i<v.size(); i++) 
            if (v[i] > v[i-1]) profit += v[i]-v[i-1];
        return profit;
    }
};
