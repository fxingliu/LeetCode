class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        // median is one number
        if (sum & 1) return findKth(nums1, nums2, 0, 0, sum/2);
        else return (findKth(nums1, nums2, 0, 0, sum/2-1) + findKth(nums1, nums2, 0, 0, sum/2)) / 2.0;
    }
    
private:
    int findKth(vector<int>& a, vector<int>& b, int ia, int ib, int k) {
        // ensure m <= n
        if (a.size()-ia > b.size()-ib) return findKth(b, a, ib, ia, k);
        if (a.size() == ia) return b[ib+k];
        if (k == 0) return min(a[ia], b[ib]);
        int i = min((k-1)/2, (int)a.size()-1-ia);
        int j = k-i-1;
        // throw away the smaller part
        if (a[ia+i] < b[ib+j]) return findKth(a, b, ia+i+1, ib, k-i-1);
        else if (a[ia+i] > b[ib+j]) return findKth(a, b, ia, ib+j+1, k-j-1);
        else return a[ia+i];
    }
};
