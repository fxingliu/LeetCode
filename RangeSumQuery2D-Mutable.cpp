class NumMatrix {
    struct TreeNode {
        int val = 0;
        vector<TreeNode*> sub = {NULL, NULL, NULL, NULL};
        int rowLow = 0, rowHigh = 0, colLow = 0, colHigh = 0;
        TreeNode(int v) : val(v) {}
        TreeNode(int v, int rl, int rh, int cl, int ch) : val(v), rowLow(rl), rowHigh(rh), colLow(cl), colHigh(ch) {}
    };

public:
    NumMatrix(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        m = matrix.size();
        n = m==0 ? 0 : matrix[0].size();
        root = buildTree(0, m-1, 0, n-1);
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        if (diff == 0) return;
        matrix[row][col] = val;
        updateTree(root, row, col, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        getSum(root, row1, row2, col1, col2, sum);
        return sum;
    }
    
private:
    int m, n;
    vector<vector<int>> matrix;
    TreeNode* root;
    
    TreeNode* buildTree(int rl, int rh, int cl, int ch) {
        if (rl > rh || cl > ch) return NULL;
        TreeNode* t = new TreeNode(0, rl, rh, cl, ch);
        if (rl == rh && cl == ch) t->val = matrix[rl][cl];
        else {
            int rMid = rl + (rh - rl) / 2;
            int cMid = cl + (ch - cl) / 2;
            t->sub[0] = buildTree(rl, rMid, cl, cMid);
            t->sub[1] = buildTree(rl, rMid, cMid+1, ch);
            t->sub[2] = buildTree(rMid+1, rh, cl, cMid);
            t->sub[3] = buildTree(rMid+1, rh, cMid+1, ch);
            
            for (int i=0; i<4; ++i)
                if (t->sub[i]) t->val += t->sub[i]->val;
        }
        return t;
    }
    
    void updateTree(TreeNode* t, int row, int col, int diff) {
        if (!t) return;
        if (t->rowLow <= row && row <= t->rowHigh && t->colLow <= col && col <= t->colHigh) {
            t->val += diff;
            for (int i=0; i<4; i++)
                updateTree(t->sub[i], row, col, diff);
        }
    }
    
    void getSum(TreeNode* t, int rl, int rh, int cl, int ch, int& sum) {
        if (!t) return;
        // no overlap
        int top = max(rl, t->rowLow);
        int bottom = min(rh, t->rowHigh);
        if (top > bottom) return;
        int left = max(cl, t->colLow);
        int right = min(ch, t->colHigh);
        if (left > right) return;
        
        // completely inside
        if (rl <= t->rowLow && t->rowHigh <= rh && cl <= t->colLow && t->colHigh <= ch) {
            sum += t->val;
            return;
        }
        // partial inside
        for (int i=0; i<4; ++i)
            getSum(t->sub[i], rl, rh, cl, ch, sum);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
