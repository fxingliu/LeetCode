class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int layer = 0, num = 1, i;
        while (layer < (n+1)/2) {
            int side = n-1-layer*2;
            for (i=0; i<side; ++i) ret[layer][layer+i] = num++;
            for (i=0; i<side; ++i) ret[layer+i][n-1-layer] = num++;
            for (i=0; i<side; ++i) ret[n-1-layer][n-1-layer-i] = num++;
            for (i=0; i<side; ++i) ret[n-1-layer-i][layer] = num++;
            // fulfill the center
            if (i == 0) ret[n-1-layer][n-1-layer] = num;
            layer++;
        }
        return ret;
    }
};
