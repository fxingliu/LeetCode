class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, -1, path, ret);
        return ret;
    }
    
private: 
    void dfs(vector<int>& nums, int begin, vector<int>& path, vector<vector<int>>& ret) {
        ret.push_back(path);
        for (int i=begin+1; i<nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i, path, ret);
            path.pop_back();
        }
    }
};
