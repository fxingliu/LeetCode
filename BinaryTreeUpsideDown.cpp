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
        TreeNode *cur = root, *parent = NULL, *parentLeft = NULL;
        while (cur) {
            TreeNode *next = cur->left;
            cur->left = parentLeft;
            parentLeft = cur->right;
            cur->right = parent;
            parent = cur;
            cur = next;
        }
        return parent;
    }
};
