class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> ptr(k);
        vector<int> dp{1};
        while (dp.size() < n) {
            int min_next = INT_MAX;
            for (int i=0; i<k; i++)
                min_next = min(min_next, dp[ptr[i]]*primes[i]);
            dp.push_back(min_next);
            for (int i=0; i<k; i++)
                if (min_next == dp[ptr[i]]*primes[i]) ptr[i]++;
        }
        return dp.back();
    }
};
