class Solution {
public:
    void reverseWords(string &s) {
        string copy_s(s);
        s.clear();
        int i = copy_s.size(), j = i;
        while (--i >= 0) {
            if (isspace(copy_s[i]))
                j = i;
            else if (i==0 || isspace(copy_s[i-1])) {
                if (s.size()!=0)
                    s.push_back(' ');
                s.append(copy_s, i, j-i);
            }
        }
    }
};
