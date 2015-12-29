class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        // initialize n=0
        ret.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            int count = ret.size();
            // for each previous subset, insert current number
            for (int j=0; j<count; ++j) {
                vector<int> copy(ret[j]);
                copy.push_back(nums[i]);
                ret.push_back(copy);
            }
        }
        return ret;
    }
};
