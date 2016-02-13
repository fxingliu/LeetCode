class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i=1; i<=n; i++) {
            int num = i;
            for (int j=1; j*j<=i; j++)
                num = min(num, dp[i-j*j]+1);
            dp[i] = num;
        }
        return dp[n];
    }
};
