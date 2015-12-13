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
        if (inorder.empty()) return NULL;
        
        stack<TreeNode*> s;
        int inpos = inorder.size()-1, postpos = postorder.size()-1;
        TreeNode *root = new TreeNode(postorder[postpos--]);
        s.push(root);
        TreeNode *cur = root;
        bool insertRight = true;
        
        while (postpos >= 0) {
            if (!s.empty() && s.top()->val == inorder[inpos]) {
                cur = s.top();
                s.pop();
                inpos--;
                insertRight = false;
            }
            else {
                TreeNode *next = new TreeNode(postorder[postpos--]);
                if (insertRight)
                    cur->right = next;
                else {
                    cur->left = next;
                    insertRight = true;
                }
                s.push(next);
                cur = next;
            }
        }
        return root;
    }
};
