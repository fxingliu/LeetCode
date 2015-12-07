class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        int shift = n-m, i = 0;
        if (shift > 1) return false;
        while (i<m && s[i]==t[i]) i++;
        if (i == m) return m != n;
        if (m == n) i++;
        while (i<m && s[i]==t[i+shift]) i++;
        return i == m;
    }
};
