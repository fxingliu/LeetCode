class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // last[i] is the minimum value that a subsequence of length i+1 might end with
        vector<int> last(nums.size());
        int len = 0;
        for (int n : nums) {
            int pos = binarySearch(last, 0, len, n);
            last[pos] = n;
            if (pos == len) len++;
        }
        return len;
    }
    
private:
    int binarySearch(vector<int>& v, int begin, int end, int val) {
        while (begin < end) {
            int mid = (begin+end)/2;
            if (val < v[mid]) end = mid;
            else if (v[mid] < val) begin = mid+1;
            else return mid;
        }
        return begin;
    }
};
