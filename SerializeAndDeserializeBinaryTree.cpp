/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        serial_dfs(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserial_dfs(data);
    }
    
private:
    void serial_dfs(TreeNode* p, string& s) {
        if (!p) {
            s += "n,";
            return;
        }
        s += to_string(p->val) + ",";
        serial_dfs(p->left, s);
        serial_dfs(p->right, s);
    }
    
    TreeNode* deserial_dfs(string& s) {
        int pos = s.find(',');
        string val = s.substr(0, pos);
        s = s.substr(pos+1);
        if (val == "n") return NULL;
        TreeNode* cur = new TreeNode(stoi(val));
        cur->left = deserial_dfs(s);
        cur->right = deserial_dfs(s);
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
