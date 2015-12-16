class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = -1, i;
        while (true) {
            for (i=0; i<n; i++)
                ret.push_back(matrix[row][++col]);
            if (--m == 0) break;
            for (i=0; i<m; i++)
                ret.push_back(matrix[++row][col]);
            if (--n == 0) break;
            for (i=0; i<n; i++)
                ret.push_back(matrix[row][--col]);
            if (--m == 0) break;
            for (i=0; i<m; i++)
                ret.push_back(matrix[--row][col]);
            if (--n == 0) break;
        }
        return ret;
    }
};
