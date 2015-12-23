class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        for (int i=15; i>=0; i--) 
            // precedence: '+' larger than '<<'
            if ((res + (1<<i)) <= x / (res + (1<<i))) 
                res += 1<<i;
        return res;
    }
};
