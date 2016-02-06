class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int lcs = 0;
        for (int start : nums) {
            // make sure every element is visited only once
            if (s.find(start-1) != s.end()) continue;
            int end = start+1;
            while (s.find(end) != s.end()) end++;
            lcs = max(lcs, end-start);
        }
        return lcs;
    }
};
