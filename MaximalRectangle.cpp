class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        // area = (R-L)*H
        // R scan from right to left, L from left to right. H can be from either side
        vector<int> L(n, 0), R(n, n), H(n, 0);
        int maxArea = 0;
        
        for (int i=0; i<m; i++) {
            int left = 0, right = n;
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '1') {
                    L[j] = max(L[j], left);
                    H[j]++;
                }
                else {
                    L[j] = 0;
                    H[j] = 0;
                    left = j+1;
                }
            }
            
            for (int j=n-1; j>=0; j--) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    maxArea = max(maxArea, (R[j]-L[j])*H[j]);
                }
                else {
                    R[j] = n;
                    right = j;
                }
            }
        }
        return maxArea;
    }
};
