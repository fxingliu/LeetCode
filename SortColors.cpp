class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        for (int i=0; i<=high; ) {
            if (nums[i] == 0) 
                swap(nums[low++], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[high--], nums[i]);
            else
                i++;
        }
    }
};
