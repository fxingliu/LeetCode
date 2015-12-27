class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(nums, 0, ret);
        return ret;
    }
    
private:
    void dfs(vector<int>& nums, int pos, vector<vector<int>>& ret) {
        if (pos == nums.size()) {
            ret.push_back(nums);
            return;
        }
        for (int begin=pos; begin<nums.size(); ++begin) {
            swap(nums[pos], nums[begin]);
            dfs(nums, pos+1, ret);
            swap(nums[pos], nums[begin]);
        }
    }
};
