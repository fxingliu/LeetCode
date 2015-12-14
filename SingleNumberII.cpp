class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32];
        memset(bits, 0, sizeof(int)*32);
        int ret = 0;
        for (int i=0; i<32; ++i) {
            for (int n : nums) 
                if (n>>i & 1) bits[i]++;
            ret |= bits[i]%3 << i;
        }
        return ret;
    }
};
