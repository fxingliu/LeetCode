class Solution {
typedef int (Solution::*fptr)(int, int);

public:
    Solution() {
        fmap.insert(make_pair("+", &Solution::plus));
        fmap.insert(make_pair("-", &Solution::minus));
        fmap.insert(make_pair("*", &Solution::multi));
        fmap.insert(make_pair("/", &Solution::div));
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = 0;
        while (n < tokens.size()) {
            string cur = tokens[n++];
            if (isNumber(cur)) s.push(stoi(cur));
            else {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                fptr fp = fmap[cur];
                s.push((this->*fp)(x, y));
            }
        }
        return s.top();
    }
  
private:
    bool isNumber(string &s) {
        return s.size() > 1 || isdigit(s[0]);
    }
    
    int plus(int x, int y) { return x + y; }
    int minus(int x, int y) { return x - y; }
    int multi(int x, int y) { return x * y; }
    int div(int x, int y) { return x / y; }
    
    unordered_map<string, fptr> fmap;
};
