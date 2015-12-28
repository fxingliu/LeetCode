class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        length = nums.size();
        unordered_map<int, int> m;
        for (int& n : nums) {
            if (m.find(n) == m.end()) m[n] = 1;
            else m[n] += 1;
        }
        // convert the map to vector as the input set
        vector<pair<int, int>> pairs(m.begin(), m.end());
        vector<int> path;
        vector<vector<int>> ret;
        dfs(pairs, path, ret);
        return ret;
    }
    
int length;
private:
    void dfs(vector<pair<int, int>>& pairs, vector<int>& path, vector<vector<int>>& ret) {
        if (path.size() == length) {
            ret.push_back(path);
            return;
        }
        for (auto& it : pairs) {
            int count = 0;
            for (int& n : path) 
                if (n == it.first) count++;
            if (count < it.second) {
                path.push_back(it.first);
                dfs(pairs, path, ret);
                path.pop_back();
            }
        }
    }
};
