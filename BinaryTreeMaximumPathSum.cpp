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
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        findMax(root);
        return maxSum;
    }
    
private:
    int maxSum;
    
    int findMax(TreeNode *p) {
        if (!p) return 0;
        int left = findMax(p->left);
        int right = findMax(p->right);
        maxSum = max(left + right + p->val, maxSum);
        int ret = p->val + max(left, right);
        return max(ret, 0);
    }
};
