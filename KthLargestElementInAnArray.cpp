class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);
        for (int i=0; i<k-1; i++) {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
    
private:
    int heapSize;
    
    void maxHeapify(vector<int>& nums, int idx) {
        int l = 2*idx+1, r = 2*idx+2, maxIdx = idx;
        if (l < heapSize && nums[l] > nums[maxIdx]) maxIdx = l;
        if (r < heapSize && nums[r] > nums[maxIdx]) maxIdx = r;
        if (maxIdx != idx) {
            swap(nums[maxIdx], nums[idx]);
            maxHeapify(nums, maxIdx);
        }
    }
    
    void buildHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i=heapSize/2-1; i>=0; i--)
            maxHeapify(nums, i);
    }
};
