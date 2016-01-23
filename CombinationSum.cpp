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
    void dfs(vector<vector<int>>& ret, vector<int>& path, int start, int target, vector<int>& candidates) {
        if (target == 0) {
            ret.push_back(path);
            return;
        }
        for (int i=start; i<candidates.size(); i++) {
            // early prunning
            if (candidates[i] > target) continue;
            path.push_back(candidates[i]);
            dfs(ret, path, i, target-candidates[i], candidates);
            path.pop_back();
        }
    }
};
