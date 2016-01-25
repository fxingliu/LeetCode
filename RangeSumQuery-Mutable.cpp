class NumArray {
public:
    NumArray(vector<int> &nums) : n(nums.size()) {
        if (n == 0) return;
        int size = 1;
        while (size < n) size*=2;
        size = 2*size-1;
        segmentTree.resize(size);
        buildTree(0, nums, 0, n-1);
    }

    void update(int i, int val) {
        getUpdate(0, i, val, 0, n-1);
    }

    int sumRange(int i, int j) {
        return getSum(0, i, j, 0, n-1);
    }
    
private:
    vector<int> segmentTree;
    const int n;
    
    int buildTree(int pos, vector<int>& nums, int begin, int end) {
        if (begin == end) {
            segmentTree[pos] = nums[begin]; 
            return segmentTree[pos];
        }
        // avoid overflow
        int mid = begin + (end - begin) / 2;
        // recursively build left and right subtree 
        segmentTree[pos] = buildTree(2*pos+1, nums, begin, mid) + buildTree(2*pos+2, nums, mid+1, end);
        return segmentTree[pos];
    }
    
    int getUpdate(int pos, int i, int val, int begin, int end) {
        if (i < begin || end < i) return 0;
        int diff;
        // found i
        if (begin == end) {
            diff = val - segmentTree[pos];
            segmentTree[pos] = val;
            return diff;
        }
        int mid = begin + (end - begin) / 2;
        diff = (mid < i) ? getUpdate(2*pos+2, i, val, mid+1, end) : getUpdate(2*pos+1, i, val, begin, mid);
        segmentTree[pos] += diff;
        return diff;
    }
    
    int getSum(int pos, int i, int j, int begin, int end) {
        if (i <= begin && end <= j) return segmentTree[pos];
        if (end < i || j < begin) return 0;
        int mid = begin + (end - begin) / 2;
        return getSum(2*pos+1, i, j, begin, mid) + getSum(2*pos+2, i, j, mid+1, end);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
