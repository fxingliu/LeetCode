class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n < 3) return 0;
        vector<int> leftMax(n, height.front()), rightMax(n, height.back());
        for (int i=1; i<n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        for (int i=n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        int area = 0;
        for (int i=0; i<n; i++) {
            int side = min(leftMax[i], rightMax[i]);
            if (side > height[i]) area += side-height[i];
        }
        return area;
    }
};
