class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        if (n < 2) return 0;
        vector<int> dp(n);
        int longest = 0;
        
        // dp[0] must be 0
        for (int i=1; i<n; i++) 
            if (s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >= 0) ? dp[i-dp[i-1]-2] : 0);
                longest = max(longest, dp[i]);
            }
        return longest;
    }
};
