class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;    
        while (1) {
            int ret = partition(nums, left, right);
            if (ret == k-1) return nums[ret];
            else if (ret < k-1) left = ret + 1;
            else right = ret - 1;
        }
    }
    
private:
    int partition(vector<int>& nums, int left, int right) {
        if (left == right) return left;
        int pivot = nums[left], L = left+1, R = right;
        while (L <= R) {
            if (nums[L] < pivot && nums[R] > pivot) swap(nums[L++], nums[R--]);
            if (nums[L] >= pivot) L++;
            if (nums[R] <= pivot) R--;
        }
        swap(nums[left], nums[R]);
        return R;
    }
};
