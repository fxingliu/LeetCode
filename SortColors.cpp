class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last0 = partition(nums, 0, 0);
        partition(nums, last0, 1);
    }
    
private:
    int partition(vector<int>& nums, int begin, int key) {
        if (begin >= nums.size()) return nums.size();
        int pos = begin;
        for (; begin < nums.size(); begin++)
            if (nums[begin] == key) swap(nums[begin], nums[pos++]);
        return pos;
    }
};
