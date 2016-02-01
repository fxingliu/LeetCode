class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n < 3) return 0;
        int maxIdx = 0;
        for (int i=1; i<n; i++)
            if (height[i] > height[maxIdx]) maxIdx = i;
            
        int peak = 0, area = 0;
        for (int i=0; i<maxIdx; i++) {
            if (height[i] > peak) peak = height[i];
            else area += peak-height[i];
        }
        peak = 0;
        for (int i=n-1; i>maxIdx; i--) {
            if (height[i] > peak) peak = height[i];
            else area += peak-height[i];
        }
        
        return area;
    }
};
