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
        list = head;
        ListNode *p = head;
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        return convert(len);
    }
    
private:
    ListNode *list;
    
    TreeNode* convert(int len) {
        if (len == 0) return NULL;
        TreeNode *lchild = convert(len/2);
        TreeNode *cur = new TreeNode(list->val);
        cur->left = lchild;
        list = list->next;
        cur->right = convert(len-len/2-1);
        return cur;
    }
};
