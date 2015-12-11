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
        return convert(0, len-1);
    }
    
private:
    ListNode *list;
    
    TreeNode* convert(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2; 
        TreeNode *lchild = convert(start, mid-1);
        TreeNode *cur = new TreeNode(list->val);
        cur->left = lchild;
        list = list->next;
        cur->right = convert(mid+1, end);
        return cur;
    }
};
