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
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return checkBST(root);
    }

private:
    TreeNode* prev;
    bool checkBST(TreeNode *t) {
        if (!t) return true;
        if (checkBST(t->left)) {
            if (prev && t->val <= prev->val) return false;
            prev = t;
            return checkBST(t->right);
        }
        return false;
    }
};
