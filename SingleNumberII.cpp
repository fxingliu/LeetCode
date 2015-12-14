class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // x[i] indicates bits appear i times 
        int x0 = ~0, x1 = 0, x2 = 0;
        for (int n : nums) {
            int tmp = x2;
            x2 = x1 & n | x2 & ~n;
            x1 = x0 & n | x1 & ~n;
            x0 = tmp & n | x0 & ~n;
        }
        return x1;
    }
};
