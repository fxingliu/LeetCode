class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ret;
        unordered_map<char, int> m;
        
        int odd = 0;
        for (char& c : s) {
            m[c] += 1;
            odd += (m[c] % 2) ? 1 : -1;
        }
        if (odd > 1) return ret;
        
        single = "";
        for (auto& it : m) {
            if (it.second % 2) 
                single = it.first;
            // no need to -1 for single 
            it.second /= 2;
        }
        
        string path;
        halfLen = s.size() / 2;
        dfs(ret, path, m);
        return ret;
    }
    
private:
    int halfLen;
    string single;
    
    void dfs(vector<string>& ret, string& path, const unordered_map<char, int>& m) {
        // construct from half the palindrome
        if (path.size() == halfLen) {
            string cur = path + single;
            for (int i=halfLen-1; i>=0; i--) cur += path[i];
            ret.push_back(cur);
            return;
        }
        
        for (auto& it : m) {
            int count = 0;
            for (char& c : path)
                if (c == it.first) count++;
            if (count < it.second) {
                path.push_back(it.first);
                dfs(ret, path, m);
                path.pop_back();
            }
        } 
    }
};
