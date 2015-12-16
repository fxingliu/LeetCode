class Solution {
public:
    string intToRoman(int num) {
        int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ret;
        
        int i = 0;
        while (num > 0) {
            int n = num / radix[i];
            while (n-- > 0) ret.append(roman[i]);
            num %= radix[i];
            i++;
        }
        return ret;
    }
};
