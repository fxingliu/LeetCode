class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ensure m <= n
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        const int m = nums1.size(), n = nums2.size();
        int imin = 0, imax = m, half = (m+n+1)/2, med1, med2, i, j;
        
        while (imin <= imax) {
            i = (imin+imax)/2;
            j = half-i;
            if (i>0 && j<n && nums2[j]<nums1[i-1]) imax = i-1;
            else if (i<m && j>0 && nums1[i]<nums2[j-1]) imin = i+1;
            else {
                if (i == 0) med1 = nums2[j-1];
                else if (j == 0) med1 = nums1[i-1];
                else med1 = max(nums1[i-1], nums2[j-1]);
                break;
            }
        }
        
        if ((m+n) & 1) // sum is odd, only one median
            return med1;
        if (i == m) med2 = nums2[j];
        else if (j == n) med2 = nums1[i];
        else med2 = min(nums1[i], nums2[j]);
        return (med1 + med2) / 2.0;
    }
};
