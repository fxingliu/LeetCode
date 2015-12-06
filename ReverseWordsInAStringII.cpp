class Solution {
public:
    void reverseWords(string &s) {
        reverse(s, 0, s.size());
        int i=0;
        for (int j=0; j<=s.size(); j++) {
            if (isspace(s[j]) || j == s.size()) {
                reverse(s, i, j);
                i = j+1;
            }
        }
    }
    
private:
    void reverse(string &s, int begin, int end) {
        char tmp;
        end--;
        while (begin < end) {
            tmp = s[begin];
            s[begin++] = s[end];
            s[end--] = tmp;
        }
    }
};
