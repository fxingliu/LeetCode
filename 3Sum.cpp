class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        const int n = nums.size();
        if (n < 3) return ret;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; ++i) {
            // consider duplicate
            if (i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i], j = i+1, k = n-1;
            while (j<k) {
                if (nums[j] + nums[k] < target) ++j;
                else if (nums[j] + nums[k] > target) --k;
                else {
                    vector<int> tmp{nums[i], nums[j], nums[k]};
                    ret.push_back(tmp);
                    while (j<k && nums[j]==nums[j+1]) ++j;
                    while (j<k && nums[k]==nums[k-1]) --k;
                    ++j; --k;
                }
            }
        }
        
        return ret;
    }
};
