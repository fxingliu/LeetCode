class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        // get the XOR of two single numbers
        for (int n : nums)
            mask ^= n;
        // get the last bit 1
        mask &= -mask;
        // separate into 2 groups
        int ret[2] = {0};
        for (int n : nums) {
            if (n & mask) ret[0] ^= n;
            else ret[1] ^= n;
        }
        return vector<int>(ret, ret+2);
    }
};
