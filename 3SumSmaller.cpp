class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        for (int i=0; i<n; i++) {
            int j = i+1, k = n-1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < target) {
                    count += k-j;
                    j++;
                }
                else k--;
            }
        }
        return count;
    }
};
