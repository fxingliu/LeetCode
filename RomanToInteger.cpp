class Solution {
public:
    int romanToInt(string s) {
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int radix[] = {1000, 500, 100, 50, 10, 5, 1};
        unordered_map<char, int> m;
        for (int i=0; i<7; i++)
            m[roman[i]] = radix[i];
            
        int val = 0, prev = 0;
        for (char &c : s) {
            int cur = m[c];
            val += cur>prev ? cur-2*prev : cur;
            prev = cur;
        }
        return val;
    }
};
