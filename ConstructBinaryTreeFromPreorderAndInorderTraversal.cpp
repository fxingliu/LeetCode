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
        if (preorder.empty()) return NULL;
        
        stack<TreeNode*> s;
        int prepos = 0, inpos = 0;
        bool insertLeft = true;
        TreeNode *root = new TreeNode(preorder[0]);
        s.push(root);
        prepos++;
        TreeNode *cur = root;
        
        while (prepos < preorder.size()) {
            if (!s.empty() && s.top()->val == inorder[inpos]) {
                cur = s.top();
                s.pop();
                inpos++;
                insertLeft = false;
            }
            else {
                TreeNode *next = new TreeNode(preorder[prepos]);
                if (insertLeft) 
                    cur->left = next;
                else {
                    cur->right = next;
                    insertLeft = true;
                }
                s.push(next);
                prepos++;
                cur = next;
            }
        }
        
        return root;
    }
};
