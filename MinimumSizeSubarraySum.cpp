class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int begin = 0, end = 0, sum = 0, minLen = INT_MAX;
        while (end<nums.size()) {
            sum += nums[end++];
            while (sum >= s) {
                minLen = min(minLen, end-begin);
                sum -= nums[begin++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
