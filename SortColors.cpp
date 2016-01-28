class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int n : nums)
            count[n]++;
        int idx = 0;
        for (int i=0; i<3; i++)
            while (count[i]--) nums[idx++] = i;
    }
};
