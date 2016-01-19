class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), min_gap = INT_MAX, ret;
        for (int i=0; i<n; i++) {
            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int gap = abs(sum-target);
                if (gap < min_gap) {
                    min_gap = gap;
                    ret = sum;
                }
                if (sum < target) j++;
                else k--;
            }
        }
        return ret;
    }
};
