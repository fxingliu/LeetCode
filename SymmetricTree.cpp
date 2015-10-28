class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> s;
        
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            TreeNode *r = s.top();
            s.pop();
            TreeNode *l = s.top();
            s.pop();
            if (!r && !l) continue;
            if (!r || !l) return false;
            if (r->val != l->val) return false;
            
            s.push(r->right);
            s.push(l->left);
            s.push(r->left);
            s.push(l->right);
        }
        return true;
    }
};
