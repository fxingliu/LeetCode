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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }
    
private:
    vector<TreeNode*> generate(int begin, int end) {
        vector<TreeNode*> ret;
        if (begin > end) {
            ret.push_back(NULL);
            return ret;
        }
        
        for (int i=begin; i<=end; ++i) {
            vector<TreeNode*> L = generate(begin, i-1);
            vector<TreeNode*> R = generate(i+1, end);
            for (TreeNode* l : L)
                for (TreeNode* r : R) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    ret.push_back(cur);
                }
        }
        
        return ret;
    }
};
