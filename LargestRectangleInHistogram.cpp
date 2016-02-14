class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        heights.push_back(0);
        
        for (int i=0; i<heights.size(); i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int cur = s.top();
                s.pop();
                int j = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, (i-j-1)*heights[cur]);
            }
            s.push(i);
        }
        return maxArea;
    }
};
