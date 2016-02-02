class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        const int m = costs.size(), n = costs[0].size();
        vector<int> last(n), min_last(n);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                last[j] = min_last[j] + costs[i][j];
            // update min_last in two-pass traversal
            if (i == m-1) break;
            min_last[0] = INT_MAX;
            for (int j=1; j<n; j++)
                min_last[j] = min(min_last[j-1], last[j-1]);
            int tmp = last.back();
            for (int j=n-2; j>=0; j--) {
                tmp = min(tmp, last[j+1]);
                min_last[j] = min(min_last[j], tmp);
            } 
        }
        
        int ret = last[0];
        for (int j=1; j<n; j++)
            ret = min(ret, last[j]);
        return ret;
    }
};
