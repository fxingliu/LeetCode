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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        ret.push_back(vector<int>());
        queue<TreeNode*> q;
        q.push(root);
        // use NULL to separate each level
        q.push(NULL);
        
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (!p) {
                if (!q.empty()) {
                    ret.push_back(vector<int>());
                    q.push(NULL);
                }
                continue;
            }
            ret.back().push_back(p->val);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        
        return ret;
    }
};
