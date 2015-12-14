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
        travel(root, 0, true);
        return ret;
    }

private: 
    vector<vector<int>> ret;
    
    void travel(TreeNode *node, int level, bool L2R) {
        if (!node) return;
        if (level == ret.size()) ret.push_back(vector<int>());
        if (L2R) ret[level].push_back(node->val);
        else ret[level].insert(ret[level].begin(), node->val);
        travel(node->left, level+1, !L2R);
        travel(node->right, level+1, !L2R);
    }
};
