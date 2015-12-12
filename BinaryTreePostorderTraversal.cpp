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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *prev = NULL;
        stack<TreeNode*> s;
        vector<int> ret;
        do {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            prev = NULL;
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                // just visited right child
                if (prev == cur->right) {
                    ret.push_back(cur->val);
                    prev = cur;
                }
                else {
                    s.push(cur);
                    cur = cur->right;
                    break;
                }
                
            }
        } while (!s.empty());
        return ret;
    }
};
