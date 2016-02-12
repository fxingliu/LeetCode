class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly{1};
        int i=0, j=0, k=0;
        while (ugly.size() < n) {
            int cur = min(min(ugly[i]*2, ugly[j]*3), ugly[k]*5);
            ugly.push_back(cur);
            if (cur == ugly[i]*2) i++;
            if (cur == ugly[j]*3) j++;
            if (cur == ugly[k]*5) k++;
        }
        return ugly.back();
    }
};
