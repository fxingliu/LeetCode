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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        ret.push_back(vector<int>());
        
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (!p) {
                if (!q.empty()) {
                    ret.insert(ret.begin(), vector<int>());
                    q.push(NULL);
                }
                continue;
            }
            ret[0].push_back(p->val);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        
        return ret;
    }
};
