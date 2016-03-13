class Solution {
    // memoization 
    unordered_map<string, vector<string>> m;
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (m.count(s)) return m[s];
        vector<string> ret;
        // check the whole string
        if (wordDict.count(s)) ret.push_back(s);
        for (int i=1; i<s.size(); i++) {
            string first(s, 0, i), second(s, i);
            if (wordDict.count(second)) {
                vector<string> firstRet = wordBreak(first, wordDict);
                for (auto& it : firstRet) ret.push_back(it + " " + second);
            }
        }
        m[s] = ret;
        return ret;
    }
};
