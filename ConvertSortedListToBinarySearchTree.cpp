/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        return convert(head, len);
    }
    
private:
    TreeNode* convert(ListNode *node, int len) {
        if (len == 0 || !node) return NULL;
        if (len == 1) return new TreeNode(node->val);
        
        ListNode *p = node;
        int step = len/2;
        while (step>0) {
            p = p->next;
            step--;
        }
        TreeNode *cur = new TreeNode(p->val);
        cur->left = convert(node, len/2);
        cur->right = convert(p->next, len-len/2-1);
        return cur;
    }
};
