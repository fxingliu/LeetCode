class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        stack<string> s;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') i++;
            int j = i;
            while (j < path.size() && path[j] != '/') j++;
            string cur = path.substr(i, j-i);
            i = j;
            if (cur == "." || cur == "") continue;
            if (cur == "..") {
                if (!s.empty()) s.pop();
            }
            else s.push(cur);
        }
        if (s.empty()) return "/";
        while (!s.empty()) {
            ret = "/" + s.top() + ret;
            s.pop();
        }
        return ret;
    }
};
