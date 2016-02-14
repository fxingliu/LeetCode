class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        // H[j] is the current height at [i][j]. H[n] = 0 as a sentinel
        vector<int> H(n+1);
        int maxArea = 0;
        
        for (int i=0; i<m; i++) {
            stack<int> s;
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '0') H[j] = 0;
                else H[j]++;
            }
            for (int j=0; j<=n; j++) {
                while (!s.empty() && H[s.top()] > H[j]) {
                    int cur = s.top();
                    s.pop();
                    int k = s.empty() ? -1 : s.top();
                    maxArea = max(maxArea, (j-k-1)*H[cur]);
                }
                s.push(j);
            }
        }
        return maxArea;
    }
};
