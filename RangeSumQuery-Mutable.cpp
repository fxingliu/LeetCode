class NumArray {
public:
    NumArray(vector<int> &nums) : n(nums.size()) {
        this->nums = nums;
        // construct BIT
        BIT = vector<int>(n+1, 0);
        for (int i=0; i<n; i++) {
            updateBIT(i, nums[i]);
        }
    }

    void update(int i, int val) {
        updateBIT(i, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
    
private:
    vector<int> nums;
    vector<int> BIT;
    const int n;
    
    void updateBIT(int i, int diff) {
        // the index of BIT is i+1
        i++;
        while (i <= n) {
            BIT[i] += diff;
            i += i & (-i);
        }
    }
    
    int getSum(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= i & (-i);
        } 
        return sum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
