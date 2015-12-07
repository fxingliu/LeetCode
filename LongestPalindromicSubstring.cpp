class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), start = 0, end = 0;
        if (len < 2) return s;
        for (int i=0; i<len; i++) {
            int len1 = centric(s, i, i);
            int len2 = centric(s, i, i+1);
            int len = max(len1, len2);
            if (len > end-start+1) {
                start = i - (len-1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end-start+1);
    }
    
private:
    int centric(string s, int L, int R) {
        while (L >= 0 && R < s.size()) {
            if (s[L] != s[R]) break;
            L--;
            R++;
        }
        return R-L-1;
    }
};
