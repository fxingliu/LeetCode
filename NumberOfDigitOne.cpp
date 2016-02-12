class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        int digit = 1, count = 0;
        // (digit*10 <= n) may lead to overflow
        while (digit <= n/10) digit *= 10;
        while (digit) {
            int pre = n/digit/10, cur = n/digit%10;
            if (cur == 0) 
                count += pre*digit;
            else if (cur == 1) 
                count += pre*digit + n%digit + 1;
            else 
                count += (pre+1)*digit;
            digit /= 10;
        }
        return count;
    }
};
