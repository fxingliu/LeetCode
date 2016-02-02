class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) return ret;
        string path;
        dfs(ret, digits, path, 0);
    }
    
private:
    vector<string> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(vector<string>& ret, string& digits, string& path, int begin) {
        if (begin == digits.size()) {
            ret.push_back(path);
            return;
        }
        string letter = map[digits[begin]-'0'];
        for (char c : letter) {
            path.push_back(c);
            dfs(ret, digits, path, begin+1);
            path.pop_back();
        }
    }
};
