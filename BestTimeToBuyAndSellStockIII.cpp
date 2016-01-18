class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int n = prices.size();
        vector<int> first(n, 0);
        vector<int> second(n, 0);
        for (int i=1, valley=prices[0]; i<n; ++i) {
            first[i] = max(first[i-1], prices[i]-valley);
            valley = min(valley, prices[i]);
        }
        for (int i=n-2, peak=prices[n-1]; i>=0; --i) {
            second[i] = max(second[i+1], peak-prices[i]);
            peak = max(peak, prices[i]);
        }
        
        int max_profit = 0;
        for (int i=0; i<n; ++i)
            max_profit = max(max_profit, first[i]+second[i]);
            
        return max_profit;
    }
};
