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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        ret.push_back(vector<int>());
        bool L2R = true;
        
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (!p) {
                L2R = !L2R;
                if (!q.empty()) {
                    ret.push_back(vector<int>());
                    q.push(NULL);
                }
                continue;
            }
            if (L2R) ret.back().push_back(p->val);
            else ret.back().insert(ret.back().begin(), p->val);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        
        return ret;
    }
};
