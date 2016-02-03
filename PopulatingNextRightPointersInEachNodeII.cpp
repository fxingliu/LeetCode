/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *headDown = NULL; // head of next level
        TreeLinkNode *curDown = NULL; // cur node of next level
        TreeLinkNode *cur = root; // cur node of cur level
        
        while (cur) {
            // iterate on current level
            while (cur) {
                if (cur->left) {
                    if (headDown) curDown->next = cur->left;
                    else headDown = cur->left;
                    curDown = cur->left;
                }
                if (cur->right) {
                    if (headDown) curDown->next = cur->right;
                    else headDown = cur->right;
                    curDown = cur->right;
                }
                cur = cur->next;
            }
            
            cur = headDown;
            headDown = NULL;
            curDown = NULL;
        }
    }
};
