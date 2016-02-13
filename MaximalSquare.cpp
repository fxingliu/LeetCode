class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        const int m = matrix.size(), n = matrix[0].size();
        // pad a zero at the beginning
        vector<int> dp(n+1);
        int maxLen = 0, pre = 0;
        
        for (int i=0; i<m; i++)
            for (int j=1; j<=n; j++) {
                int tmp = dp[j];
                if (matrix[i][j-1] == '0') dp[j] = 0;
                else {
                    dp[j] = min(min(dp[j], dp[j-1]), pre) + 1;
                    maxLen = max(maxLen, dp[j]);
                }
                pre = tmp;
            }
            
        return maxLen*maxLen;
    }
};
