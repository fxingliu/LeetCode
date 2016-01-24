class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sum(nums.size()+1);
        getSum(nums, sum);
        int minLen = INT_MAX;
        for (int end=1; end<=nums.size(); ++end) {
            if (sum[end] >= s) {
                // the first element such that sum[begin] > sum[end] - s
                int begin = binarySearch(sum, sum[end]-s);
                if (begin <= end) minLen = min(minLen, end-begin+1);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
    
private:
    // construct the accumulate sum array
    void getSum(vector<int>& nums, vector<int>& sum) {
        sum[0] = 0;
        for (int i=0; i<nums.size(); ++i)
            sum[i+1] = sum[i] + nums[i];
    }
    
    int binarySearch(vector<int>& v, int target) {
        int L = 0, R = v.size()-1;
        while (L < R) {
            int M = (L+R)/2;
            if (v[M] < target) L = M+1;
            else R = M;
        }
        return v[L] <= target ? L+1 : L;
    }
};
