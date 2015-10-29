class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        vector<int> next = cal_next(needle);
        int j=-1;
        for (int i=0; i<haystack.size(); i++) {
            while (j>-1 && haystack[i]!=needle[j+1])
                j = next[j];
            if (haystack[i] == needle[j+1])
                j++;
            if (j == needle.size()-1) // match
                return i-j;
        }
        return -1;
    }
    
private:
    // calculate next[]
    vector<int> cal_next(string s) {
        vector<int> next(s.size(), -1);
        int j = -1;
        for (int i=1; i<s.size(); i++) {
            while (j>-1 && s[i]!=s[j+1]) 
                j = next[j];
            if (s[i] == s[j+1]) j++;
            next[i] = j;
        }
        return next;
    }
};
