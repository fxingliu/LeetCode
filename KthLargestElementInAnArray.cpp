class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        return nums[nums.size()-k];
    }
    
private:
    int quickSort(vector<int>& nums, int left, int right) {
        int pivot = nums[(left+right)/2], L = left, R = right;
        while (L <= R) {
            while (nums[L] < pivot) L++;
            while (nums[R] > pivot) R--;
            if (L <= R) swap(nums[L++], nums[R--]);
        }
        if (L < right) quickSort(nums, L, right);
        if (R > left) quickSort(nums, left, R);
    }
};
