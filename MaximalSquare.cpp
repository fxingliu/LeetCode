class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        for (int i=0; i<m; i++) {
            dp[i][0] = matrix[i][0]-'0';
            if (dp[i][0]) maxLen = 1;
        }
        for (int j=0; j<n; j++) {
            dp[0][j] = matrix[0][j]-'0';
            if (dp[0][j]) maxLen = 1;
        }
        
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
            
        return maxLen*maxLen;
    }
};
