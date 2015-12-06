class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // calculate the number of each char in the current substring
        unordered_map<char, int> map;
        int maxlen = 0, numChar = 0, start = 0;
        for (int i=0; i<s.size(); i++) {
            auto iter = map.find(s[i]);
            if (iter == map.end() || iter->second == 0) {
                map[s[i]] = 1;
                numChar++;
            }
            else
                map[s[i]] += 1;
            while (numChar > 2) {
                if (--map[s[start]] == 0)
                    numChar--;
                start++;
            }
            maxlen = max(maxlen, i-start+1);
        }
        return maxlen;
    }
};
