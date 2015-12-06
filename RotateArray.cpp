class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2 || k < 0) return;
        k %= len;
        // first reverse first n-k elements, then last k elements, finally all elements
        reverse(nums, 0, len-k);
        reverse(nums, len-k, k);
        reverse(nums, 0, len);
    }
    
private:
    void reverse(vector<int>& arr, int start, int num) {
        int tmp, end = start + num - 1;
        while (start < end) {
            tmp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = tmp;
        }
    }
};
