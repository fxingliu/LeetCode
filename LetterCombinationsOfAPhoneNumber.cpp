class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty()) return vector<string>();
        
        deque<string> ret;
        ret.push_back("");
        while (ret.front().size() < digits.size()) {
            string cur = ret.front();
            ret.pop_front();
            string letter = map[digits[cur.size()]-'0'];
            for (char c : letter)
                ret.push_back(cur+c);
        }
        
        return vector<string>(ret.begin(), ret.end());
    }
};
