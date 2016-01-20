class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int n = nums.size();
        vector<int> lis(n, 1);
        for (int i=1; i<n; ++i) 
            for (int j=0; j<i; ++j) 
                if (nums[j] < nums[i] && lis[j]+1 > lis[i]) lis[i] = lis[j]+1;
        int max_len = 1;
        for (int j=0; j<n; ++j)
            if (lis[j] > max_len) max_len = lis[j];
        return max_len;
    }
};
