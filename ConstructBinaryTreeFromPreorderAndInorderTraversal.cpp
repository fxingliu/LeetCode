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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildNode(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }
    
private:
    // assume pe-ps == ie-is
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps == pe) return NULL;
        TreeNode *cur = new TreeNode(preorder[ps]);
        // locate cur in inorder
        int pos;
        for (pos=is; pos<ie; pos++) 
            if (inorder[pos] == preorder[ps]) break;
        cur->left = buildNode(preorder, inorder, ps+1, ps+1+pos-is, is, pos);
        cur->right = buildNode(preorder, inorder, ps+1+pos-is, pe, pos+1, ie);
        return cur;
    }
};
