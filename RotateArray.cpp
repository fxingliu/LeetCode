class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2 || k <= 0) return;
        int countRotated = 0, start = 0, cur = 0, tmp;
        while (countRotated < len) {
            do {
                cur = (cur+k) % len;
                tmp = nums[cur];
                nums[cur] = nums[start];
                nums[start] = tmp;
                countRotated++;
            }
            while (start != cur);
            // start a new cycle
            start++;
            cur = start;
        }
    }
};
