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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> _stack;
        while (root) {
            _stack.push(root);
            if (p->val < root->val) root = root->left;
            else root = root->right;
        }
        while (!_stack.empty()) {
            root = _stack.top();
            _stack.pop();
            if (root->val > p->val) return root;
        }
        return NULL;
    }
};
