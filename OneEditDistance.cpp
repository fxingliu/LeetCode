class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return checkInsert(t, s);
        else if (m < n) return checkInsert(s, t);
        return checkReplace(s, t);
    }
    
private:
    // assume len(s)<len(t)
    bool checkInsert(string s, string t) {
        if (t.size() - s.size() != 1) return false;
        int i = 0, j = 0;
        while (i < s.size()) {
            if (s[i] != t[j]) {
                if (i != j) return false;
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        return true;
    }
    
    // assume len(s)==len(t)
    bool checkReplace(string s, string t) {
        bool found = false;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != t[i]) {
                if (found) return false;
                found = true;
            }
        }
        return found;
    }
};
