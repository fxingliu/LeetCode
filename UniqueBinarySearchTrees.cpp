class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        // f[n] = sum(f[i-1]*f[n-i]), i in 1...n
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i=2; i<=n; ++i) 
            for (int j=1; j<=i; ++j)
                f[i] += f[j-1]*f[i-j];
        return f[n];
    }
};
