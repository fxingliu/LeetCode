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
        view(root, 0, ret);
        return ret;
    }
    
private:
    void view(TreeNode *p, int layer, vector<int>& ret) {
        if (!p) return;
        if (layer == ret.size()) ret.push_back(p->val);
        view(p->right, layer+1, ret);
        view(p->left, layer+1, ret);
    }
};
