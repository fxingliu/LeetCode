class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        // avoid overflow
        unsigned long long p;
        if (n < 0) {
            x = 1/x;
            p = -n;
        }
        else p = n;
        while (p) {
            if (p & 1) ans *= x;
            x *= x;
            p >>= 1;
        }
        return ans;
    }
};
