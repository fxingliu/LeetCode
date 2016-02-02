class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        if (n == 0) return 0;
        
        stack<int> _stack;
        for (int i=0; i<n; i++) {
            if (s[i] == ')' && !_stack.empty() && s[_stack.top()] == '(') _stack.pop();
            else _stack.push(i);
        }
        
        if (_stack.empty()) return n;
        
        int start = 0, end = n, longest = 0;
        while (!_stack.empty()) {
            start = _stack.top();
            _stack.pop();
            longest = max(longest, end-start-1);
            end = start;
        }
        longest = max(longest, end);
        return longest;
    }
};
