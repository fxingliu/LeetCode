class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, path, -1, target, candidates);
        return ret;
    }
    
private:
    void dfs(vector<vector<int>>& ret, vector<int>& path, int start, int target, vector<int>& candidates) {
        if (target == 0) {
            ret.push_back(path);
            return;
        }
        for (int i=start+1; i<candidates.size(); i++) {
            // remove duplicates in current step
            if (i > start+1 && candidates[i]==candidates[i-1]) continue;
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            dfs(ret, path, i, target-candidates[i], candidates);
            path.pop_back();
            
        }
    }
};
