class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return "";
        vector<int> count(26, 0);
        int pos = 0;
        for (char c : s) count[c-'a']++;
        for (int i=0; i<s.size(); i++) {
            if (s[i] < s[pos]) pos = i;
            if (--count[s[i]-'a'] == 0) break;
        }
        return s.at(pos) + removeDuplicateLetters(strip(s.substr(pos+1), s[pos]));
    }
    
private:
    string strip(string s, char key) {
        if (s.empty()) return "";
        int idx = 0;
        string ret;
        for (char c : s) 
            if (c != key) ret.push_back(c);
        return ret;
    }
};
