class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), start = 0, end = 0;
        // indicate whether s[i->j] is palindrome
        bool flag[len][len];
        memset(flag, 0, len*len*sizeof(bool));
        
        for (int i=len-1; i>=0; i--) 
            for (int j=i; j<len; j++) {
                if (i == j) flag[i][j] = true;
                else if (i+1 == j) flag[i][j] = s[i] == s[j];
                else flag[i][j] = s[i]==s[j] && flag[i+1][j-1];
                
                if (flag[i][j] && j-i > end-start) {
                    start = i;
                    end = j;
                }
            }
                
        return s.substr(start, end-start+1);
    }
};
