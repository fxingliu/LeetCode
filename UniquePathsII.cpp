class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        if (obstacleGrid[0][0] == 1) return 0;
        cur[0] = 1;
        for (int j=0; j<n; j++) 
            for (int i=0; i<m; i++) {
                if (obstacleGrid[i][j] == 1)
                    cur[i] = 0;
                else if (i > 0)
                    cur[i] += cur[i-1];
            }
        return cur[m-1];
    }
};
