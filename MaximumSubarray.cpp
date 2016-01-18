class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return sub(nums, 0, nums.size()-1);
    }
    
private:
    int sub(vector<int>& nums, int L, int R) {
        if (L == R) return nums[L];
        int M = (L+R)/2;
        int leftSub = sub(nums, L, M);
        int rightSub = sub(nums, M+1, R);
        
        int leftPart = INT_MIN, rightPart = INT_MIN, sum = 0;
        for (int i=M; i>=L; --i) {
            sum += nums[i];
            if (sum > leftPart) leftPart = sum;
        }
        sum = 0;
        for (int i=M+1; i<=R; ++i) {
            sum += nums[i];
            if (sum > rightPart) rightPart = sum;
        }
        sum = leftPart + rightPart;
        return max(sum, max(leftSub, rightSub));
    }
};
