class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, path, 1, n, k);
        return ret;
    }
    
private:
    void dfs(vector<vector<int>>& ret, vector<int>& path, int begin, int sum, int count) {
        if (count == 0) {
            if (sum == 0) ret.push_back(path);
            return;
        }
        for (int i=begin; i<=9; i++) {
            // early prunning
            if (i > sum) break;
            path.push_back(i);
            dfs(ret, path, i+1, sum-i, count-1);
            path.pop_back();
        }
    }
};
