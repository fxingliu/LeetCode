class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int lcs = 0;
        for (int i : nums) {
            if (m.find(i) != m.end()) continue;
            int left = (m.find(i-1) != m.end()) ? m[i-1] : 0;
            int right = (m.find(i+1) != m.end()) ? m[i+1] : 0;
            int sum = left + 1 + right;
            lcs = max(lcs, sum);
            m[i] = sum;
            m[i-left] = sum;
            m[i+right] = sum;
        }
        return lcs;
    }
};
