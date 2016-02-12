class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (int digit=1; digit<=n; digit*=10) {
            int prev = n/digit, next = n%digit;
            if (prev%10 < 1) count += prev/10*digit;
            else if (prev%10 == 1) count += prev/10*digit + next + 1;
            else count += (prev/10+1)*digit;
            // avoid overflow
            if (digit > INT_MAX/10) break;
        }
        return count;
    }
};
