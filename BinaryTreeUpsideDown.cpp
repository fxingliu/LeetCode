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
        if (!root) return NULL;
        newroot = NULL;
        TreeNode *rightmost = convertHelper(root);
        rightmost->left = NULL;
        rightmost->right = NULL;
        return newroot;
    }
    
private: 
    TreeNode* convertHelper(TreeNode *node) {
        if (!node->left) {
            newroot = node;
            return node;
        }
        TreeNode *cur = convertHelper(node->left);
        cur->left = node->right;
        cur->right = node;
        return node;
    }
    
    TreeNode *newroot;
};
