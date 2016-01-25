class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> s;
        int begin = 0, end = 0;
        while (begin < n) {
            while (end<n-1 && nums[end+1] == nums[end]+1) end++;
            if (end > begin) s.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
            else s.push_back(to_string(nums[end]));
            begin = ++end;
        }
        return s;
    }
};
