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
        travel(root, 0, ret);
        return ret;
    }
    
private:
    void travel(TreeNode *node, int level, vector<vector<int>> &v) {
        if (!node) return;
        if (level >= v.size()) v.push_back(vector<int>());
        v[level].push_back(node->val);
        travel(node->left, level+1, v);
        travel(node->right, level+1, v);
    }
};
