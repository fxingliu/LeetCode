class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> _set;
        for (char& c : s) {
            if (_set.find(c) != _set.end()) _set.erase(c);
            else _set.insert(c);
        }
        return _set.size() < 2;
    }
};
