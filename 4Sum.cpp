class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        const int n = nums.size();
        if (n < 4) return ret;
        
        sort(nums.begin(), nums.end());
        // mp[sum] = all pairs of index
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                mp[nums[i]+nums[j]].push_back(make_pair(i, j));
                
        vector<int> last(0);
        for (int i=0; i<n; i++) {
            // avoid duplicates
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<n; j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int sum = target - nums[i] - nums[j];
                if (mp.find(sum) == mp.end()) continue;
                for (auto &p : mp[sum]) {
                    int s = p.first;
                    int t = p.second;
                    // ensure i<j<s<t
                    if (j >= s) continue;
                    vector<int> v{nums[i], nums[j], nums[s], nums[t]};
                    if (last != v) ret.push_back(v);
                    last = v;
                }
            }
        }
        return ret;
    }
};
