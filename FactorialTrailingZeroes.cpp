class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        for (int i=5; i<=n; i*=5) {
            zeroes += n/i;
            if (i > INT_MAX/5) break;
        }
        return zeroes;
    }
};
