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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, path, root, sum);
        return ret;
    }
    
private:
    void dfs(vector<vector<int>> &ret, vector<int>& path, TreeNode* p, int sum) {
        if (!p) return;
        path.push_back(p->val);
        if (!p->left && !p->right && sum == p->val) ret.push_back(path);
        if (p->left) dfs(ret, path, p->left, sum-p->val);
        if (p->right) dfs(ret, path, p->right, sum-p->val);
        path.pop_back();
    }
};
