class Solution {
public:
    int findMin(vector<int>& nums) {
        int L=0, R=nums.size()-1;
        while (L<R) {
            int M = (L+R)/2;
            if (nums[M] < nums[R]) R = M;
            else L = M+1;
        }
        return nums[L];
    }
};
