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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }
    
private:
    TreeNode *convert(vector<int>& arr, int start, int end) {
        if (start > end) return NULL;
        int mid = (start+end)/2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = convert(arr, start, mid-1);
        node->right = convert(arr, mid+1, end);
        return node;
    }
};
