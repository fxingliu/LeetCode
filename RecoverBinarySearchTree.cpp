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
    void recoverTree(TreeNode* root) {
        inorder(root);
        int p = 0, q = ptr.size()-1;
        while (p+1 < ptr.size() && ptr[p]->val < ptr[p+1]->val) p++;
        while (q-1 >= 0 && ptr[q-1]->val < ptr[q]->val) q--;
        int tmp = ptr[p]->val;
        ptr[p]->val = ptr[q]->val;
        ptr[q]->val = tmp;
    }
    
private:
    vector<TreeNode*> ptr;
    
    void inorder(TreeNode *p) {
        if (!p) return;
        inorder(p->left);
        ptr.push_back(p);
        inorder(p->right);
    }
};
