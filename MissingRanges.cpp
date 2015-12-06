class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int prev = lower - 1;
        for (int i : nums) {
            if (i-prev > 1) appendRange(ans, prev+1, i-1);
            prev = i;
        }
        appendRange(ans, prev+1, upper);
        return ans;
    }
    
private:
    void appendRange(vector<string>& ans, int lower, int upper) {
        if (lower > upper) return;
        if (lower == upper) ans.push_back(to_string(lower));
        else ans.push_back(to_string(lower) + "->" + to_string(upper));
    }
};
