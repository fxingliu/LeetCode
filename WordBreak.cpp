class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for (int i=1; i<=s.size(); i++) {
            // move j backward may be a bit more proficient
            for (int j=i-1; j>=0; j--) {
                if (dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};