class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k%n;
        if (k==0) return;
        int *tmp = new int[k];
        for (int i=0; i<k; i++)
            tmp[i] = nums[n-k+i];
        for (int i=n-k-1; i>=0; i--)
            nums[i+k] = nums[i];
        for (int i=0; i<k; i++)
            nums[i] = tmp[i];
        delete tmp;
    }
};
