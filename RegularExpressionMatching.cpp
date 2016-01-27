class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
         const int m = s.size(), n = p.size();
         vector<vector<bool>> f(m+1, vector<bool>(n+1, false));
         // two empty strings match
         f[0][0] = true;
         
         // update p[j-1] == '*'
         for (int j=2; j<=n; ++j)
            f[0][j] = p[j-1]=='*' && f[0][j-2];
            
         // normal case
         for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++) {
                if (p[j-1] != '*') f[i][j] = f[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                // no need to check j>=2, since p[0] cannot be '*'
                else f[i][j] = f[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && f[i-1][j];
            }
            
        return f[m][n];
    }
};
