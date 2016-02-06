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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        lcs(root, 0, root->val);
        return maxLen;
    }
    
private:
    int maxLen = 0;
    
    void lcs(TreeNode* p, int len, int target) {
        if (!p) return;
        len = (p->val == target) ? len+1 : 1;
        maxLen = max(maxLen, len);
        lcs(p->left, len, p->val+1);
        lcs(p->right, len, p->val+1);
    }
};
