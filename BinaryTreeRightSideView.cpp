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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        
        deque<TreeNode*> q;
        q.push_back(root);
        TreeNode *rightmost = root;
        while (!q.empty()) {
            root = q.front();
            q.pop_front();
            if (root->left) q.push_back(root->left);
            if (root->right) q.push_back(root->right);
            if (root == rightmost) {
                ret.push_back(root->val);
                if (!q.empty()) rightmost = q.back();
            }
        }
        
        return ret;
    }
};
