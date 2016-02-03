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
        if (!root) return;
        connectNodes(root->left, root->right);
    }
    
private:
    void connectNodes(TreeLinkNode *p, TreeLinkNode *q) {
        if (!p) return;
        p->next = q;
        connectNodes(p->left, p->right);
        connectNodes(q->left, q->right);
        connectNodes(p->right, q->left);
    }
};
