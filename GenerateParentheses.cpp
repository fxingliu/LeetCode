class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string buf;
        helper(ret, buf, n, n);
        return ret;
    }
    
private:
    void helper(vector<string>& ret, string &buf, int left, int right) {
        if (left > right || left < 0) return; 
        if (left + right == 0) ret.push_back(buf);
        else {
            // use buffer to avoid create new string
            buf.push_back('(');
            helper(ret, buf, left-1, right);
            buf.pop_back();
            buf.push_back(')');
            helper(ret, buf, left, right-1);
            buf.pop_back();
        }
    }
};
