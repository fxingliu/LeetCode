class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i : nums)
            if (!idx || i != nums[idx-1]) nums[idx++] = i;
        return idx;
    }
};
