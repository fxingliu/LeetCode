class Solution {
public:
    Solution() {
        m.insert(make_pair('(', ')'));
        m.insert(make_pair('{', '}'));
        m.insert(make_pair('[', ']'));
    }
    
    bool isValid(string s) {
        stack<char> stack;
        for (char &c : s) {
            if (m.find(c) != m.end()) stack.push(c);
            else {
                if (stack.empty()) return false;
                char last = stack.top();
                stack.pop();
                if (m[last] != c) return false;
            }
        }
        return stack.empty();
    }
    
private:
    unordered_map<char, char> m;
};
