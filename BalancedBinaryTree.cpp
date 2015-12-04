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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    
private:
    int depth(TreeNode *t) {
        if (!t) return 0;
        int l = depth(t->left);
        if (l<0) return -1;
        int r = depth(t->right);
        if (r<0) return -1;
        return (abs(l-r) <= 1) ? (max(l, r) + 1) : -1;
    }
};
