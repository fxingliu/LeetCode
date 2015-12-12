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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return convertHelper(root, NULL);
    }

private:
    TreeNode* convertHelper(TreeNode *node, TreeNode *parent) {
        if (!node) return parent;
        TreeNode *cur = convertHelper(node->left, node);
        node->left = (parent) ? parent->right : NULL;
        node->right = parent;
        return cur;
    }
};
