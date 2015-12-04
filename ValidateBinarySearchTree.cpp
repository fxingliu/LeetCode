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
        return checkBST(root, NULL, NULL);
    }
    
private:
    bool checkBST(TreeNode *t, TreeNode *min, TreeNode *max) {
        if (!t) return true;
        if (min && t->val <= min->val || max && t->val >= max->val) return false;
        return checkBST(t->left, min, t) && checkBST(t->right, t, max);
    }
};
