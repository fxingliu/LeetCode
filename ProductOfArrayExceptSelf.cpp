class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ret(n);
        if (n == 0) return ret;
        
        ret[0] = 1;
        for (int i=1; i<n; i++) 
            ret[i] = ret[i-1]*nums[i-1];
        
        int backward = 1;
        for (int i=n-2; i>=0; i--) {
            backward *= nums[i+1];
            ret[i] *= backward;
        }
        
        return ret;
    }
};
