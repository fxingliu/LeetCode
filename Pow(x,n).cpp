class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1./pow(x, -n);
        return pow(x, n);
    }
    
private:
    // x^n = x^(n/2) * x^(n/2) * x^(n%2)
    double pow(double x, int n) {
        if (n == 0) return 1;
        double p = pow(x, n/2);
        if (n%2) return p*p*x;
        return p*p;
    }
};
