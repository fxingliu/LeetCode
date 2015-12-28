class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(n, k, 1, path, ret);
        return ret;
    }
    
private:
    void dfs(int n, int k, int start, vector<int>& path, vector<vector<int>>& ret) {
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        // prune branches
        if (n-start+1+path.size() < k) return;
        for (int i=start; i<=n; ++i) {
            path.push_back(i);
            dfs(n, k, i+1, path, ret);
            path.pop_back();
        }
    }
};
