class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        vector<bool> inResult(26, false);
        string ret;
        
        for (char c : s) count[c-'a']++;
        for (char c : s) {
            count[c-'a']--;
            if (inResult[c-'a']) continue;
            while (!ret.empty() && c < ret.back() && count[ret.back()-'a']) {
                inResult[ret.back()-'a'] = false;
                ret.pop_back();
            }
            ret.push_back(c);
            inResult[c-'a'] = true;
        }
        
        return ret;
    }
};
