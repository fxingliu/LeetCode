class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char -> index of last occurance
        map<char, int> m;
        int max_len = 0, start = -1;
        for (int i=0; i<s.size(); ++i) {
            if (m.find(s[i]) != m.end() && m[s[i]] > start) {
                start = m[s[i]];
            }
            m[s[i]] = i;
            max_len = max(max_len, i-start);
        }
        return max_len;
    }
};
