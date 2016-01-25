class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return 0;
        int minVal = nums[0], maxVal = nums[0];
        for (int i=1; i<n; i++) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        // thus maxGap >= step
        int step = ceil((double)(maxVal - minVal) / (n - 1));
        vector<int> bucketMin(n-1, INT_MAX);
        vector<int> bucketMax(n-1, INT_MIN);
        
        for (int i : nums) {
            if (i == minVal || i == maxVal) continue;
            int ind = (i - minVal) / step;
            bucketMin[ind] = min(bucketMin[ind], i);
            bucketMax[ind] = max(bucketMax[ind], i);
        }
        
        // find maxGap from inter-bucket differences
        int maxGap = step, previous = minVal;
        for (int i=0; i<n-1; i++) {
            // some buckets may be empty
            if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN) continue;
            maxGap = max(maxGap, bucketMin[i] - previous);
            previous = bucketMax[i];
        }
        // update the last bucket
        maxGap = max(maxGap, maxVal - previous);
        return maxGap;
    }
};
