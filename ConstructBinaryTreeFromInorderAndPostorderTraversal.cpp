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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildNode(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
    
private:
    // assume ie-is == pe-ps
    TreeNode* buildNode(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if (is == ie) return NULL;
        TreeNode *cur = new TreeNode(postorder[pe-1]);
        // find current value in inorder
        int pos;
        for (pos=is; pos<ie; pos++)
            if (inorder[pos] == cur->val) break;
        cur->left = buildNode(inorder, postorder, is, pos, ps, ps-is+pos);
        cur->right = buildNode(inorder, postorder, pos+1, ie, ps-is+pos, pe-1);
        return cur;
    }
};
