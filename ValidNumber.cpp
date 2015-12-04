class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        while (i<n && isspace(s[i])) i++;
        if (i<n && (s[i]=='+' || s[i]=='-')) i++;
        bool isNum = false;
        while (i<n && isdigit(s[i])) {
          i++;
          isNum = true;
        }
        if (i<n && s[i]=='.') {
            i++;
            while (i<n && isdigit(s[i])) {
                i++;
                isNum = true;
            }
        }
        if (isNum && i<n && (s[i]=='E' || s[i]=='e')) {
            i++;
            if (s[i]=='+' || s[i]=='-') i++;
            isNum = false;
            while (i<n && isdigit(s[i])) {
                i++;
                isNum = true;
            }
        }
        while (i<n && isspace(s[i])) i++;
        
        return isNum && i==n;
    }
};
