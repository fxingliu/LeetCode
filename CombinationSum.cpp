class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, path, 0, target, candidates);
        return ret;
    }
    
private:
    void dfs(vector<vector<int>>& ret, vector<int>& path, int sum, int target, vector<int>& candidates) {
        if (sum > target) return;
        if (sum == target) {
            ret.push_back(path);
            return;
        }
        for (int i : candidates) {
            // avoid duplicates
            if (!path.empty() && i < path.back()) continue;
            path.push_back(i);
            dfs(ret, path, sum+i, target, candidates);
            path.pop_back();
        }
    }
};
