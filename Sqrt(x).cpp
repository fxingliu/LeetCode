class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int L = 1, R = x;
        while (true) {
            // avoid overflow
            int mid = L + (R-L) / 2;
            if (mid > x/mid) 
                R = mid;
            else {
                if (mid+1 <= x/(mid+1)) L = mid+1;
                else return mid;
            }
        }
    }
};
