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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // whether belong to the same subtree
        if ((root->val - p->val) * (root->val - q->val) > 0)
            return (root->val < p->val) ? lowestCommonAncestor(root->right, p, q) : lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
