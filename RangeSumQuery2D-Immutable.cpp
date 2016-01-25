class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = m==0 ? 0 : matrix[0].size();
        // (m+1)*(n+1) matrix to simplify code
        dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i-1][j-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
    
private:
    vector<vector<int>> dp;
    int m, n;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
