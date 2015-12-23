class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> result;
        vector<string> s0 = {""};
        result.push_back(s0);
        // DP equation: v(i) = '(' + v(j) + ')' + v(i-1-j), j = 0...i-1
        for (int i=1; i<=n; i++) {
            result.push_back(vector<string>());
            for (int j=0; j<i; j++) {
                for (string &s1 : result[j]) {
                    for (string &s2 : result[i-1-j])
                        result[i].push_back("(" + s1 + ")" + s2);
                }
            }
        }
        return result[n];
    }
};
