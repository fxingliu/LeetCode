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
        travel(root, 0);
        return ret;
    }
    
private:
    vector<vector<int>> ret;
    
    void travel(TreeNode *node, int level) {
        if (!node) return;
        if (level == ret.size()) ret.insert(ret.begin(), vector<int>());
        ret[ret.size()-1-level].push_back(node->val);
        travel(node->left, level+1);
        travel(node->right, level+1);
    }
};
