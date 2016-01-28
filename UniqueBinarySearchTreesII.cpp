/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> f(n+1, vector<TreeNode*>());
        if (n == 0) return f[0];
        f[0].push_back(NULL);
        
        // f[0, i] = comb(f[0, j-1] + j + f[j+1, i])
        for (int i=1; i<=n; ++i) 
            for (int j=1; j<=i; ++j) 
                for (TreeNode* l : f[j-1])
                    for (TreeNode* r : f[i-j]) {
                        TreeNode* cur = new TreeNode(j);
                        cur->left = l;
                        cur->right = clone(r, j);
                        f[i].push_back(cur);
                    }
        
        return f[n];
    }
    
private:
    // copy the structure while adding offset to value
    TreeNode* clone(TreeNode* ori, int offset) {
        if (!ori) return NULL;
        TreeNode* cur = new TreeNode(ori->val + offset);
        cur->left = clone(ori->left, offset);
        cur->right = clone(ori->right, offset);
        return cur;
    }
};
