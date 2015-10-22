class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int L = 0, R = nums.size()-1;
        while (L<R) {
            int mid = (L+R)/2;
            if (nums[mid]<target)
                L = mid + 1;
            else
                R = mid;
        }
        return (nums[L] >= target) ? L : L+1;
    }
};
