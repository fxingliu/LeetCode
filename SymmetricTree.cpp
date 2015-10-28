class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return symmetric(root->left, root->right);
    }
    
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (left && right && left->val==right->val)
            return (symmetric(left->left, right->right) && symmetric(left->right, right->left));
        return false;
    }
};
