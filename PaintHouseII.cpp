class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        const int m = costs.size(), n = costs[0].size();
        vector<int> last(n);
        // min1 is the smallest of last sum; min2 is the second to smallest
        int min1, min2;
        
        for (int i=0; i<m; i++) {
            int min1_old = i==0 ? 0 : min1;
            int min2_old = i==0 ? 0 : min2;
            min1 = min2 = INT_MAX;
            for (int j=0; j<n; j++) {
                if (last[j] == min1_old) 
                    last[j] = min2_old + costs[i][j];
                else
                    last[j] = min1_old + costs[i][j];
                    
                // update min1, min2 for every [i][j]
                if (last[j] >= min1)
                    min2 = min(min2, last[j]);
                else {
                    min2 = min1;
                    min1 = last[j];
                }
            } 
        }
        
        return min1;
    }
};
