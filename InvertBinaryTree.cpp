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
    TreeNode* invertTree(TreeNode* root) {
        invertNode(root);
        return root;
    }
    
private:
    void invertNode(TreeNode *p) {
        if (!p) return;
        TreeNode *tmp = p->left;
        p->left = p->right;
        p->right = tmp;
        
        invertNode(p->left);
        invertNode(p->right);
    }
};
