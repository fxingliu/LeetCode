class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        do {
            ret.push_back(nums);
        }
        while (nextPermute(nums));
        return ret;
    }
    
private:
    bool nextPermute(vector<int>& nums) {
        int i = nums.size()-1, j = nums.size()-1;
        while (i>0 && nums[i-1] >= nums[i]) i--;
        if (i == 0) return false;
        while (nums[j] <= nums[i-1]) j--;
        swap(nums[j], nums[i-1]);
        reverse(nums.begin()+i, nums.end());
        return true;
    }
};
