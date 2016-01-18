class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = nums[0], minVal = nums[0], maxRes = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            int mx = maxVal, mn = minVal;
            maxVal = max(max(mx*nums[i], mn*nums[i]), nums[i]);
            minVal = min(min(mx*nums[i], mn*nums[i]), nums[i]);
            maxRes = max(maxRes, maxVal);
        }
        return maxRes;
    }
};
