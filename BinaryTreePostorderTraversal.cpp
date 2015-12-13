/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct NodeWrapper {
    TreeNode *node;
    int visited;
    NodeWrapper(TreeNode *p) : node(p), visited(0) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        stack<NodeWrapper> s;
        NodeWrapper p(root);
        s.push(p);
        
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (++p.visited == 3) {
                ret.push_back(p.node->val);
                continue;
            }
            s.push(p);
            if (p.visited == 1 && p.node->left) s.push(NodeWrapper(p.node->left));
            if (p.visited == 2 && p.node->right) s.push(NodeWrapper(p.node->right));
        }
        
        return ret;
    }
};
