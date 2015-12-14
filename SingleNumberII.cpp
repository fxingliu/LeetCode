class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0, mask = 1;
        for (int i=0; i<32; i++) {
            int sum = 0;
            for (int n : nums)
                if (n & mask) sum++;
            ret |= sum%3 << i;
            mask <<= 1;
        }
        return ret;
    }
};
