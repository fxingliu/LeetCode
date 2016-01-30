class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while (low < high) {
            // count the numbers in [1, mid]
            int mid = low+(high-low)/2, count = 0;
            for (int i : nums)
                if (i <= mid) count++;
            if (count > mid) high = mid;
            else low = mid+1;
        }
        return low;
    }
};
