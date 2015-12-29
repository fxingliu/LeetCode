class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int retNum = pow(2, nums.size());
        vector<vector<int>> ret(retNum, vector<int>());
        for (int i=0; i<nums.size(); ++i) {
            // each j represents one solution
            for (int j=0; j<retNum; ++j) 
                if ((j >> i) & 1) ret[j].push_back(nums[i]);
        }
        return ret;
    }
};
