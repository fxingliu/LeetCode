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
        int sum = 0;
        dfs(sum, 0, root);
        return sum;
    }
    
private:
    void dfs(int& sum, int path, TreeNode* p) {
        if (!p) return;
        path = path * 10 + p->val;
        if (!p->left && !p->right) sum += path;
        dfs(sum, path, p->left);
        dfs(sum, path, p->right);
    }
};
