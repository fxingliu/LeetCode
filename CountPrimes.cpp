class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        // kick out even numbers
        int count = n>>1, upper = sqrt(n-1);
        vector<bool> prime(n, true);
        for (int i=3; i<=upper; i+=2)
            if (prime[i]) 
                for (int j=i*i, step=i<<1; j<n; j+=step) 
                    if (prime[j]) {
                        prime[j] = false;
                        count--;
                    }
        return count;
    }
};
