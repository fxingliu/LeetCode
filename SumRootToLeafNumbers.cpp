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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* p, int sum) {
        if (!p) return 0;
        if (!p->left && !p->right) return sum*10+p->val;
        return dfs(p->left, sum*10+p->val) + dfs(p->right, sum*10+p->val);
    }
};
