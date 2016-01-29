class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int i : nums) {
            if (i == val) continue;
            nums[idx++] = i;
        }
        return idx;
    }
};
