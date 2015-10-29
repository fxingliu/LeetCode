class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        vector<int> next = cal_next(needle);
        int i, j=-1;
        for (i=0; i<haystack.size(); i++) {
            while (j>-1 && needle[j+1]!=haystack[i])
                j = next[j];
            if (needle[j+1] == haystack[i])
                j++;
            if (j == needle.size()-1) // match
                return i-j;
            j = next[j];
        }
        return -1;
    }
    
private:
    // calculate next[]
    vector<int> cal_next(string needle) {
        vector<int> next;
        int j = -1;
        // initialize next[0] = -1
        next.push_back(j);
        for (int i=1; i<needle.size(); i++) {
            while (j>-1 && needle[j+1]!=needle[i]) 
                j = next[j];
            if (needle[j+1] == needle[i]) j++;
            next.push_back(j);
        }
        return next;
    }
};
