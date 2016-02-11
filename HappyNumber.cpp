class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> _set;
        while (n > 1) {
            int next = 0;
            while (n) {
                next += (n%10)*(n%10);
                n /= 10;
            }
            if (_set.find(next) != _set.end()) return false;
            _set.insert(next);
            n = next;
        }
        return true;
    }
};
