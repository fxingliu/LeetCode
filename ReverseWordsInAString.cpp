class Solution {
public:
    void revString(string &s, int begin, int end) {
        char tmp; 
        while (begin<end) {
            tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            ++begin;
            --end;
        }
    }
    
    void stripSpace(string &s) {
        char *tmp = new char[s.length()+1];
        int ind = 0, tmp_ind = 0;
        while (ind<s.length() && isspace(s[ind])) ind++;
        while (s[ind]) {
            if (isspace(s[ind])) {
                while (isspace(s[ind])) ind++;
                tmp[tmp_ind++] = ' ';
            }
            else tmp[tmp_ind++] = s[ind++];
        }
        while (tmp_ind>0 && isspace(tmp[tmp_ind-1])) tmp_ind--;
        tmp[tmp_ind] = '\0';
        s = string(tmp);
        delete []tmp;
    }
    
    void reverseWords(string &s) {
        if (s.length() < 1) return;
        int begin=0, end=0;
        stripSpace(s);
        while(end<s.length()) {
            if (isspace(s[end])) {
                revString(s, begin, end-1);
                begin = end+1;
                end = begin;
            }
            else
                end++;
        }
        revString(s, begin, end-1);
        revString(s, 0, s.length()-1);
    }
};
