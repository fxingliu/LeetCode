class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int area = 0;
        while (L < R) {
            area = max(area, (R-L)*min(height[L], height[R]));
            if (height[L] < height[R]) L++;
            else R--;
        }
        return area;
    }
};
