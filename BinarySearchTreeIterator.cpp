/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_stack.empty();    
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = _stack.top();
        _stack.pop();
        pushAllLeft(cur->right);
        return cur->val;
    }
    
private:
    stack<TreeNode*> _stack;
    
    void pushAllLeft(TreeNode *p) {
        while (p) {
            _stack.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
