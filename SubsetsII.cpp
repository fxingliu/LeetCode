class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int same = 1;
            while (i+same < nums.size() && nums[i] == nums[i+same]) same++;
            int prevSize = ret.size();
            for (int j=0; j<prevSize; ++j) {
                vector<int> copy(ret[j]);
                for (int k=0; k<same; ++k) {
                    copy.push_back(nums[i]);
                    ret.push_back(copy);
                }
            }
            i += same;
        }
        return ret;
    }
};
