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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder(ret, root);
        return ret;
    }
    
private:
    void inorder(vector<int> &v, TreeNode *node) {
        if (!node) return;
        inorder(v, node->left);
        v.push_back(node->val);
        inorder(v, node->right);
    }
};
